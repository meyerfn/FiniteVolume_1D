#ifndef EULERFORWARDTIMEDISCRETIZATION_HPP
#define EULERFORWARDTIMEDISCRETIZATION_HPP
#include "../abstractTimeDiscretization.hpp"

class EulerForwardTimeDiscretization : public AbstractTimeDiscretization
{
public:
    EulerForwardTimeDiscretization(
        float deltaT, unsigned int numberOfTimesteps,
        std::shared_ptr<TimeDiscretizationInterface> rightHandSide);
    ~EulerForwardTimeDiscretization() = default;
    void timestep(std::vector<float>& solutionVector) override;
};
#endif // EULERFORWARDTIMEDISCRETIZATION_HPP