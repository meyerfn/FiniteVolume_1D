#include "dirichletBoundaryCondition.hpp"

std::vector<float> DirichletBoundaryCondition::computeBoundaryValues(const std::vector<float>&)
{
    std::vector<float> boundaryCondition{0., 0.};
    return boundaryCondition;
}
