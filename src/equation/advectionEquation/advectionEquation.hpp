#ifndef ADVECTIONEQUATION_HPP
#define ADVECTIONEQUATION_HPP
#include "../abstractEquation.hpp"
class AdvectionEquation : public AbstractEquation
{
public:
    AdvectionEquation(float advectionVelocity);
    ~AdvectionEquation();
    std::vector<float> getFlux(const std::vector<float>& values) const override;
    float getSignalSpeed() const override;

private:
    float m_advectionVelocity;
};
#endif // ADVECTIONEQUATION_HPP