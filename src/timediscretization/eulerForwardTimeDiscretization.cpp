#include "eulerForwardTimeDiscretization.hpp"
#include <algorithm>

EulerForwardTimeDiscretization::EulerForwardTimeDiscretization(
    float deltaT, unsigned int numberOfTimesteps,
    std::unique_ptr<AbstractRiemann> riemann)
    : AbstractTimeDiscretization(deltaT, numberOfTimesteps, std::move(riemann))
{
}

void EulerForwardTimeDiscretization::timestep(
    std::vector<float>& solutionVector)
{
    auto flux = m_riemann->computeSurfaceIntegral(solutionVector);
    std::transform(flux.begin(), flux.end(), flux.begin(), [this](float elem) {
        return elem * EulerForwardTimeDiscretization::m_deltaT;
    });
    std::transform(solutionVector.begin(), solutionVector.end(), flux.begin(),
                   solutionVector.begin(), std::plus<double>());
}
