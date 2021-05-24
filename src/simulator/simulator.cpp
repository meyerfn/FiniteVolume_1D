#include "simulator.hpp"
#include "../../src/output/outputwriter.hpp"

Simulator::Simulator(
    std::shared_ptr<AbstractTimeDiscretization> timeDiscretization,
    std::vector<float> solution)
    : m_timeDiscretization(timeDiscretization), m_solution(solution){};
SimulationBuilder Simulator::make() { return SimulationBuilder(); }

void Simulator::runSimulation()
{
    for (int i = 0; i < m_timeDiscretization->getNumberOfTimesteps(); ++i)
    {
        m_timeDiscretization->timestep(m_solution);
    }
    OutputWriter::writeSolutionToTextFile(m_solution);
}