#ifndef ABSTRACTRIEMANN_HPP
#define ABSTRACTRIEMANN_HPP
#include "../boundaryCondition/abstractBoundaryCondition.hpp"
#include <memory>
#include <vector>

class AbstractRiemann
{
public:
    AbstractRiemann(float advectionVelocity,
                    std::unique_ptr<AbstractBoundaryCondition> bc)
        : m_advectionVelocity(advectionVelocity),
          m_boundaryCondition(std::move(bc))
    {
    }
    virtual ~AbstractRiemann() = default;
    virtual std::vector<float>
    computeFlux(const std::vector<float>& solutionVector) = 0;

protected:
    float m_advectionVelocity;
    std::unique_ptr<AbstractBoundaryCondition> m_boundaryCondition;
};

#endif // ABSTRACTRIEMANN_HPP