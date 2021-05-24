#ifndef ABSTRACTTIMEDISCRETIZATION_HPP
#define ABSTRACTTIMEDISCRETIZATION_HPP
#include "timeDiscretizationInterface.hpp"
#include <memory>

class AbstractTimeDiscretization
{
public:
    AbstractTimeDiscretization(
        float deltaT, unsigned int numberOfTimesteps,
        std::shared_ptr<TimeDiscretizationInterface> rightHandSide)
        : m_deltaT(deltaT), m_numberOfTimesteps(numberOfTimesteps),
          m_rightHandSide(rightHandSide)
    {
    }

    virtual ~AbstractTimeDiscretization() = default;
    virtual void timestep(std::vector<float>& solutionVector) = 0;
    unsigned int getNumberOfTimesteps() const { return m_numberOfTimesteps; }

protected:
    std::shared_ptr<TimeDiscretizationInterface> m_rightHandSide;
    float m_deltaT;
    unsigned int m_numberOfTimesteps;
};

#endif // ABSTRACTTIMEDISCRETIZATION_HPP
