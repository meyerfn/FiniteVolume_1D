#ifndef ABSTRACTBOUNDARYCONDITION_HPP
#define ABSTRACTBOUNDARYCONDITION_HPP
#include <vector>

class AbstractBoundarycondition
{
public:
    AbstractBoundarycondition() = default;
    virtual ~AbstractBoundarycondition() = default;
    virtual std::vector<float>
    computeBoundaryValues(const std::vector<float>&) = 0;
};

#endif // ABSTRACTBOUNDARYCONDITION_HPP