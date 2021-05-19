#ifndef ABSTRACTTIMEDISCRETIZATION_HPP
#define ABSTRACTTIMEDISCRETIZATION_HPP
#include "timeDiscretizationInterface.hpp"
#include <memory>

class AbstractTimeDiscretization
{
public:
    AbstractTimeDiscretization(
        float deltaT,
        std::unique_ptr<TimeDiscretizationInterface> rightHandSide)
        : m_deltaT(deltaT), m_rightHandSide(std::move(rightHandSide))
    {
    }

    virtual ~AbstractTimeDiscretization() = default;
    virtual void timestep(std::vector<float>& solutionVector) = 0;

protected:
    std::unique_ptr<TimeDiscretizationInterface> m_rightHandSide;
    float m_deltaT;
};

#endif // ABSTRACTTIMEDISCRETIZATION_HPP
