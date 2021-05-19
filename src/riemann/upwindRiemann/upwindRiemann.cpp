#include "upwindRiemann.hpp"
#include "../../equation/abstractEquation.hpp"
#include <algorithm>
#include <functional>

UpwindRiemann::UpwindRiemann(std::unique_ptr<AbstractEquation> equation)
    : AbstractRiemann(std::move(equation))
{
}

UpwindRiemann::~UpwindRiemann() {}

std::vector<float>
UpwindRiemann::numericalFlux(const std::vector<float>& leftCellValues,
                             const std::vector<float>& rightCellValues) const
{
    auto riemannSolution(leftCellValues);
    const auto advectionVelocity = m_equation->getSignalSpeed();
    if (advectionVelocity >= 0)
    {
        std::transform(leftCellValues.begin(), leftCellValues.end(),
                       riemannSolution.begin(),
                       [advectionVelocity](float elem) {
                           return advectionVelocity * elem;
                       });
    }
    else
    {
        std::transform(rightCellValues.begin(), rightCellValues.end(),
                       riemannSolution.begin(),
                       [advectionVelocity](float elem) {
                           return advectionVelocity * elem;
                       });
    }
    return riemannSolution;
}
