#ifndef ABSTRACTRIEMANN_HPP
#define ABSTRACTRIEMANN_HPP
#include "../boundarycondition/abstractBoundarycondition.hpp"
#include <memory>
#include <vector>

class AbstractRiemann
{
public:
    AbstractRiemann(float advectionVelocity,
                    std::unique_ptr<AbstractBoundarycondition> bc)
        : m_advectionVelocity(advectionVelocity),
          m_boundarycondition(std::move(bc))
    {
    }
    virtual ~AbstractRiemann() = default;
    virtual std::vector<float>
    computeSurfaceIntegral(const std::vector<float>& solutionVector) = 0;

protected:
    float m_advectionVelocity;
    std::unique_ptr<AbstractBoundarycondition> m_boundarycondition;
};

#endif // ABSTRACTRIEMANN_HPP