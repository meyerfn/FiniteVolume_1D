#include "surfaceintegral.hpp"
#include "../boundarycondition/abstractBoundarycondition.hpp"
#include "../riemann/abstractRiemann.hpp"
#include <algorithm>

Surfaceintegral::Surfaceintegral(float meshWidth,
                                 std::unique_ptr<AbstractRiemann> riemann,
                                 std::unique_ptr<AbstractBoundarycondition> bc)
    : m_meshWidth(meshWidth), m_riemann(std::move(riemann)), m_bc(std::move(bc))
{
}

std::vector<float> Surfaceintegral::computeSurfaceintegral(
    const std::vector<float>& solutionVector)
{
    auto fluxUpperBoundary =
        computeNumericalFluxUpperBoundaries(solutionVector);
    auto fluxLowerBoundary =
        computeNumericalFluxLowerBoundaries(solutionVector);
    auto surfaceintegral =
        accumulateFluxes(fluxLowerBoundary, fluxUpperBoundary);

    return surfaceintegral;
}

std::vector<float> Surfaceintegral::computeNumericalFluxUpperBoundaries(
    const std::vector<float>& solutionVector)
{
    std::vector<float> leftCellValueUpperBoundary(solutionVector);
    std::vector<float> rightCellValueUpperBoundary =
        fillRightCellValuesAtUpperBoundaries(solutionVector);
    auto fluxUpperBoundary = m_riemann->numericalFlux(
        leftCellValueUpperBoundary, rightCellValueUpperBoundary);
    return fluxUpperBoundary;
}

std::vector<float> Surfaceintegral::computeNumericalFluxLowerBoundaries(
    const std::vector<float>& solutionVector)
{
    auto rightCellValueLowerBoundary(solutionVector);
    std::vector<float> leftCellValueLowerBoundary =
        fillLeftCellValuesAtLowerBoundaries(solutionVector);

    auto fluxLowerBoundary = m_riemann->numericalFlux(
        leftCellValueLowerBoundary, rightCellValueLowerBoundary);
    return fluxLowerBoundary;
}

std::vector<float> Surfaceintegral::fillRightCellValuesAtUpperBoundaries(
    const std::vector<float>& solutionVector)
{
    std::vector<float> rightCellValueUpperBoundary{};
    rightCellValueUpperBoundary.insert(rightCellValueUpperBoundary.begin(),
                                       solutionVector.begin() + 1,
                                       solutionVector.end());
    rightCellValueUpperBoundary.push_back(
        m_bc->computeBoundaryValues(solutionVector)[1]);
    return rightCellValueUpperBoundary;
}

std::vector<float> Surfaceintegral::fillLeftCellValuesAtLowerBoundaries(
    const std::vector<float>& solutionVector)
{
    std::vector<float> leftCellValueLowerBoundary{};
    leftCellValueLowerBoundary.push_back(
        m_bc->computeBoundaryValues(solutionVector)[0]);
    leftCellValueLowerBoundary.insert(leftCellValueLowerBoundary.begin() + 1,
                                      solutionVector.begin(),
                                      solutionVector.end() - 1);
    return leftCellValueLowerBoundary;
}

std::vector<float>
Surfaceintegral::accumulateFluxes(const std::vector<float>& fluxLowerBoundary,
                                  const std::vector<float>& fluxUpperBoundary)
{
    std::vector<float> surfaceintegral{fluxLowerBoundary};
    std::transform(fluxUpperBoundary.begin(), fluxUpperBoundary.end(),
                   fluxLowerBoundary.begin(), surfaceintegral.begin(),
                   std::minus<float>());
    std::transform(
        surfaceintegral.begin(), surfaceintegral.end(), surfaceintegral.begin(),
        [this](float elem) { return -1. * elem * (1. / m_meshWidth); });
    return surfaceintegral;
}
