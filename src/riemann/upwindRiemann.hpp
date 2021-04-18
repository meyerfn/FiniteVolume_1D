#ifndef UPWINDRIEMANN_HPP
#define UPWINDRIEMANN_HPP
#include "abstractRiemann.hpp"

class UpwindRiemann : public AbstractRiemann
{
public:
    UpwindRiemann(float advectionVelocity,
                  std::unique_ptr<AbstractBoundaryCondition> bc);
    ~UpwindRiemann();
    std::vector<float>
    computeFlux(const std::vector<float>& solutionVector) override;

private:
    std::vector<float>
    computeInteriorFlux(const std::vector<float>& solutionVector);
    std::vector<float>
    computeBoundaryFlux(const std::vector<float>& solutionVector);
};

#endif // UPWINDRIEMANN_HPP