#include "advectionEquation.hpp"
#include <algorithm>

AdvectionEquation::AdvectionEquation(float advectionVelocity)
    : m_advectionVelocity(advectionVelocity)
{
}

AdvectionEquation::~AdvectionEquation() {}

std::vector<float>
AdvectionEquation::getFlux(const std::vector<float>& values) const
{
    std::vector<float> flux(values);
    std::transform(values.begin(), values.end(), flux.begin(),
                   [this](float value) { return value * m_advectionVelocity; });
    return flux;
}

float AdvectionEquation::getSignalSpeed() const { return m_advectionVelocity; }
