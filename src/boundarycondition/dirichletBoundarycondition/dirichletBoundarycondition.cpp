#include "dirichletBoundarycondition.hpp"

std::vector<float>
DirichletBoundarycondition::computeBoundaryValues(const std::vector<float>&)
{
    std::vector<float> boundaryCondition{0., 0.};
    return boundaryCondition;
}
