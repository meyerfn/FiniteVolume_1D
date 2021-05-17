#ifndef SURFACEINTEGRAL_HPP
#define SURFACEINTEGRAL_HPP
#include <memory>
#include <vector>

class AbstractRiemann;
class AbstractBoundarycondition;

class Surfaceintegral
{
public:
    Surfaceintegral(float meshWidth, std::unique_ptr<AbstractRiemann> riemann,
                    std::unique_ptr<AbstractBoundarycondition> bc);
    std::vector<float>
    computeSurfaceintegral(const std::vector<float>& solutionVector);

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
    std::unique_ptr<AbstractRiemann> m_riemann;
    std::unique_ptr<AbstractBoundarycondition> m_bc;
};
#endif // SURFACEINTEGRAL_HPP