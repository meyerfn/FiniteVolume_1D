#ifndef ABSTRACTTIMEDISCRETIZATION_HPP
#define ABSTRACTTIMEDISCRETIZATION_HPP
#include "../riemann/abstractRiemann.hpp"
#include <memory>

class AbstractTimeDiscretization
{
public:
    AbstractTimeDiscretization(float deltaT,
                               std::unique_ptr<AbstractRiemann> riemann);
    virtual ~AbstractTimeDiscretization() = default;
    virtual void timestep(std::vector<float>& solutionVector) = 0;

protected:
    std::unique_ptr<AbstractRiemann> m_riemann;
    float m_deltaT;
};

#endif // ABSTRACTTIMEDISCRETIZATION_HPP
