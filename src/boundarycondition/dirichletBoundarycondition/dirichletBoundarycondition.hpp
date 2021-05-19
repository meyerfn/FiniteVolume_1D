#ifndef DIRICHLETBOUNDARYCONDITION_HPP
#define DIRICHLETBOUNDARYCONDITION_HPP
#include "../abstractBoundarycondition.hpp"

class DirichletBoundarycondition : public AbstractBoundarycondition
{
public:
    DirichletBoundarycondition() {}
    ~DirichletBoundarycondition() {}
    std::vector<float>
    computeBoundaryValues(const std::vector<float>& solution) override;
};
#endif // DIRICHLETBOUNDARYCONDITION_HPP