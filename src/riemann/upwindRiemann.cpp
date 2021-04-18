#include "upwindRiemann.hpp"
#include <algorithm>
#include <functional>

UpwindRiemann::UpwindRiemann(float advectionVelocity,std::unique_ptr<AbstractBoundaryCondition> bc)
    : AbstractRiemann(advectionVelocity, std::move(bc))
{
}
UpwindRiemann::~UpwindRiemann() {}

std::vector<float>
UpwindRiemann::computeFlux(const std::vector<float>& solutionVector)
{
    const auto numberOfCells = solutionVector.size();
    auto numericalFlux = computeInteriorFlux(solutionVector);
    const auto boundaryFlux = m_boundaryCondition->computeBoundaryValues(solutionVector);
    numericalFlux[0] = boundaryFlux[0];
    numericalFlux[numberOfCells - 1] = boundaryFlux[1];
    return numericalFlux;
}

std::vector<float>
UpwindRiemann::computeInteriorFlux(const std::vector<float>& solutionVector)
{
    auto numberOfCells = solutionVector.size();
    std::vector<float> interiorValues(numberOfCells);
    std::transform(solutionVector.begin(), solutionVector.end() - 1,
                   solutionVector.begin() + 1, interiorValues.begin(),
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

    return interiorValues;
}
