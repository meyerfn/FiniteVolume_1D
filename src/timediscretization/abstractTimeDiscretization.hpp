#ifndef ABSTRACTTIMEDISCRETIZATION_HPP
#define ABSTRACTTIMEDISCRETIZATION_HPP
#include "../riemann/abstractRiemann.hpp"
#include <memory>

class AbstractTimeDiscretization
{
public:
    AbstractTimeDiscretization(float deltaT, unsigned int numberOfTimesteps,
                               std::unique_ptr<AbstractRiemann> riemann);
    virtual ~AbstractTimeDiscretization() = default;
    virtual void timestep(std::vector<float>& solutionVector) = 0;

protected:
    std::unique_ptr<AbstractRiemann> m_riemann;
    float m_deltaT;
    unsigned int m_numberOfTimesteps;
};

#endif // ABSTRACTTIMEDISCRETIZATION_HPP
