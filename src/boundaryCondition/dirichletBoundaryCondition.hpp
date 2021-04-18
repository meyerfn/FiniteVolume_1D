#ifndef DIRICHLETBOUNDARYCONDITION_HPP
#define DIRICHLETBOUNDARYCONDITION_HPP
#include "abstractBoundaryCondition.hpp"

class DirichletBoundaryCondition : public AbstractBoundaryCondition
{
public:
    DirichletBoundaryCondition() {}
    ~DirichletBoundaryCondition() {}
    std::vector<float> computeBoundaryValues(const std::vector<float>& solution) override;
};
#endif // DIRICHLETBOUNDARYCONDITION_HPP