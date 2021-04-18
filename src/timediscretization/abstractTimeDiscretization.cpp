#include "abstractTimeDiscretization.hpp"

AbstractTimeDiscretization::AbstractTimeDiscretization(
    float deltaT, std::unique_ptr<AbstractRiemann> riemann)
    : m_deltaT(deltaT), m_riemann(std::move(riemann))
{
}
