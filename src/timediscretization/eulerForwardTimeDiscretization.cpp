#include "eulerForwardTimeDiscretization.hpp"
#include <algorithm>

EulerForwardTimeDiscretization::EulerForwardTimeDiscretization(
    float deltaT, std::unique_ptr<AbstractRiemann> riemann)
    : AbstractTimeDiscretization(deltaT, std::move(riemann))
{
}

void EulerForwardTimeDiscretization::timestep(
    std::vector<float>& solutionVector)
{
    auto flux = m_riemann->computeFlux(solutionVector);
    std::transform(flux.begin(), flux.end(), flux.begin(), [this](float flux) {
        return flux * EulerForwardTimeDiscretization::m_deltaT;
    });
    std::transform(solutionVector.begin(), solutionVector.end(), flux.begin(),
                   solutionVector.begin(), std::plus<double>());
}
