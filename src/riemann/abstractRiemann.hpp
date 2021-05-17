#ifndef ABSTRACTRIEMANN_HPP
#define ABSTRACTRIEMANN_HPP
#include "../equation/abstractEquation.hpp"
#include <memory>
#include <vector>

class AbstractEquation;

class AbstractRiemann
{
public:
    AbstractRiemann(std::unique_ptr<AbstractEquation> equation)
        : m_equation(std::move(equation))
    {
    }
    virtual ~AbstractRiemann() = default;
    virtual std::vector<float>
    numericalFlux(const std::vector<float>& leftCellValues,
                  const std::vector<float>& rightCellValues) const = 0;

protected:
    std::unique_ptr<AbstractEquation> m_equation;
};

#endif // ABSTRACTRIEMANN_HPP