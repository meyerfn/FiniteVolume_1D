#ifndef UPWINDRIEMANN_HPP
#define UPWINDRIEMANN_HPP
#include "abstractRiemann.hpp"
#include <tuple>

class UpwindRiemann : public AbstractRiemann
{
public:
    UpwindRiemann(float advectionVelocity,
                  std::unique_ptr<AbstractBoundarycondition> bc);
    ~UpwindRiemann();
    std::vector<float>
    computeSurfaceIntegral(const std::vector<float>& solutionVector) override;

private:
    std::tuple<std::vector<float>, std::vector<float>>
    computeBoundaryFluxes(const std::vector<float>& solutionVector);

    void fillInnerValues(const std::vector<float>& solution,
                         std::vector<float>& leftCellValues,
                         std::vector<float>& rightCellValues);

    void fillValuesAtBoundaries(const std::vector<float>& solution,
                                std::vector<float>& leftCellValues,
                                std::vector<float>& rightCellValues);
};

#endif // UPWINDRIEMANN_HPP