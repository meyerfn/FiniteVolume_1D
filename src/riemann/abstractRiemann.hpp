#ifndef ABSTRACTRIEMANN_HPP
#define ABSTRACTRIEMANN_HPP
#include "../equation/abstractEquation.hpp"
#include "../timediscretization/timeDiscretizationInterface.hpp"
#include <memory>
#include <vector>

class AbstractEquation;

class AbstractRiemann
{
public:
    AbstractRiemann(std::shared_ptr<AbstractEquation> equation)
        : m_equation(equation)
    {
    }
    virtual ~AbstractRiemann() = default;
    virtual std::vector<float>
    numericalFlux(const std::vector<float>& leftCellValues,
                  const std::vector<float>& rightCellValues) const = 0;

protected:
    std::shared_ptr<AbstractEquation> m_equation;
};

#endif // ABSTRACTRIEMANN_HPP