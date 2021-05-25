#ifndef ABSTRACTEQUATION_HPP
#define ABSTRACTEQUATION_HPP
#include <vector>
class AbstractEquation
{
public:
    virtual ~AbstractEquation(){};
    virtual std::vector<float>
    getFlux(const std::vector<float>& values) const = 0;
    virtual float getSignalSpeed() const = 0;
};
#endif // ABSTRACTEQUATION_HPP