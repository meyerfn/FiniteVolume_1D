#include "upwindRiemann.hpp"
#include <algorithm>
#include <functional>

UpwindRiemann::UpwindRiemann(float advectionVelocity, float meshWidth,
                             std::unique_ptr<AbstractBoundarycondition> bc)
    : AbstractRiemann(advectionVelocity, meshWidth, std::move(bc))
{
}
UpwindRiemann::~UpwindRiemann() {}

std::vector<float>
UpwindRiemann::computeSurfaceIntegral(const std::vector<float>& solutionVector)
{
    auto boundaryFluxes = computeBoundaryFluxes(solutionVector);
    auto leftCellValues = std::get<0>(boundaryFluxes);
    auto rightCellValues = std::get<1>(boundaryFluxes);
    std::vector<float> surfaceintegral(solutionVector.size(), 0.F);
    std::transform(rightCellValues.begin(), rightCellValues.end(),
                   leftCellValues.begin(), surfaceintegral.begin(),
                   std::minus<float>());
    std::transform(surfaceintegral.begin(), surfaceintegral.end(),
                   surfaceintegral.begin(),
                   [this](float elem) { return -1. * elem * m_meshWidth; });
    return surfaceintegral;
}

std::tuple<std::vector<float>, std::vector<float>>
UpwindRiemann::computeBoundaryFluxes(const std::vector<float>& solutionVector)
{
    std::vector<float> leftCellValues(solutionVector.size());
    std::vector<float> rightCellValues(solutionVector.size());
    fillValuesAtBoundaries(solutionVector, leftCellValues, rightCellValues);
    fillInnerValues(solutionVector, leftCellValues, rightCellValues);
    return std::make_tuple(leftCellValues, rightCellValues);
}

void UpwindRiemann::fillValuesAtBoundaries(
    const std::vector<float>& solutionVector,
    std::vector<float>& leftCellValues, std::vector<float>& rightCellValues)
{
    const auto numberOfCells = solutionVector.size();
    if (m_advectionVelocity >= 0)
    {
        leftCellValues[0] =
            m_boundarycondition->computeBoundaryValues(solutionVector)[0];
        rightCellValues[numberOfCells - 1] = solutionVector[numberOfCells - 1];
    }
    else
    {
        leftCellValues[0] = solutionVector[0];
        rightCellValues[numberOfCells - 1] =
            m_boundarycondition->computeBoundaryValues(solutionVector)[1];
    }
}

void UpwindRiemann::fillInnerValues(const std::vector<float>& solutionVector,
                                    std::vector<float>& leftCellValues,
                                    std::vector<float>& rightCellValues)
{
    std::transform(solutionVector.begin(), solutionVector.end() - 1,
                   solutionVector.begin() + 1, leftCellValues.begin() + 1,
                   [this](float uL, float uR) {
                       if (m_advectionVelocity > 0)
                       {
                           return m_advectionVelocity * uL;
                       }
                       else
                       {
                           return m_advectionVelocity * uR;
                       }
                   });

    std::transform(solutionVector.begin(), solutionVector.end() - 1,
                   solutionVector.begin() + 1, rightCellValues.begin(),
                   [this](float uL, float uR) {
                       if (m_advectionVelocity > 0)
                       {
                           return m_advectionVelocity * uL;
                       }
                       else
                       {
                           return m_advectionVelocity * uR;
                       }
                   });
}
