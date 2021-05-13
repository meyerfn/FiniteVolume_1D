#include "abstractTimeDiscretization.hpp"

AbstractTimeDiscretization::AbstractTimeDiscretization(
    float deltaT, unsigned int numberOfTimesteps,
    std::unique_ptr<AbstractRiemann> riemann)
    : m_deltaT(deltaT), m_numberOfTimesteps(numberOfTimesteps),
      m_riemann(std::move(riemann))
{
}
