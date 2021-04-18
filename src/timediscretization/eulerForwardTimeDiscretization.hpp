#ifndef EULERFORWARDTIMEDISCRETIZATION_HPP
#define EULERFORWARDTIMEDISCRETIZATION_HPP
#include "abstractTimeDiscretization.hpp"

class EulerForwardTimeDiscretization : public AbstractTimeDiscretization {
public:
    EulerForwardTimeDiscretization(float deltaT, std::unique_ptr<AbstractRiemann> riemann);
    ~EulerForwardTimeDiscretization()=default;
    void timestep(std::vector<float>& solutionVector) override;
private:
};
#endif //EULERFORWARDTIMEDISCRETIZATION_HPP