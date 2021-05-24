#ifndef SURFACEINTEGRAL_HPP
#define SURFACEINTEGRAL_HPP
#include "../timediscretization/timeDiscretizationInterface.hpp"
#include <memory>
#include <vector>

class AbstractRiemann;
class AbstractBoundarycondition;

class Surfaceintegral : public TimeDiscretizationInterface
{
public:
    Surfaceintegral(
        float meshWidth, std::shared_ptr<AbstractRiemann> riemann,
        std::shared_ptr<AbstractBoundarycondition> boundarycondition);
    std::vector<float>
    computeSurfaceintegral(const std::vector<float>& solutionVector);
    std::vector<float>
    computeRightHandSide(const std::vector<float>& solutionVector) override;

private:
    std::vector<float> fillRightCellValuesAtUpperBoundaries(
        const std::vector<float>& solutionVector);
    std::vector<float> fillLeftCellValuesAtLowerBoundaries(
        const std::vector<float>& solutionVector);
    std::vector<float> computeNumericalFluxLowerBoundaries(
        const std::vector<float>& solutionVector);
    std::vector<float> computeNumericalFluxUpperBoundaries(
        const std::vector<float>& solutionVector);
    std::vector<float>
    accumulateFluxes(const std::vector<float>& fluxLowerBoundary,
                     const std::vector<float>& fluxUpperBoundary);

    float m_meshWidth;
    std::shared_ptr<AbstractRiemann> m_riemann;
    std::shared_ptr<AbstractBoundarycondition> m_boundarycondition;
};
#endif // SURFACEINTEGRAL_HPP