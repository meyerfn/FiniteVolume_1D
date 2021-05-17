#ifndef UPWINDRIEMANN_HPP
#define UPWINDRIEMANN_HPP
#include "../equation/abstractEquation.hpp"
#include "abstractRiemann.hpp"
#include <tuple>

class UpwindRiemann : public AbstractRiemann
{
public:
    UpwindRiemann(std::unique_ptr<AbstractEquation> equation);
    ~UpwindRiemann();
    std::vector<float>
    numericalFlux(const std::vector<float>& leftCellValues,
                  const std::vector<float>& rightCellValues) const override;
};

#endif // UPWINDRIEMANN_HPP