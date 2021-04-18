#ifndef ABSTRACTBOUNDARYCONDITION_HPP
#define ABSTRACTBOUNDARYCONDITION_HPP
#include <vector>

class AbstractBoundaryCondition
{
public:
    AbstractBoundaryCondition() = default;
    virtual ~AbstractBoundaryCondition() = default;
    virtual std::vector<float> computeBoundaryValues(const std::vector<float>&) = 0;
};

#endif // ABSTRACTBOUNDARYCONDITION_HPP