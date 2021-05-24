#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include "simulationBuilder.hpp"

class Simulator
{
public:
    Simulator(std::shared_ptr<AbstractTimeDiscretization> timeDiscretization,
              std::vector<float> solution);
    static SimulationBuilder make();
    void runSimulation();

private:
    std::shared_ptr<AbstractTimeDiscretization> m_timeDiscretization;
    std::vector<float> m_solution;
};
#endif // SIMULATOR_HPP
