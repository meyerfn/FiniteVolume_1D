#ifndef SIMULATIONBUILDER_HPP
#define SIMULATIONBUILDER_HPP
#include "../boundarycondition/dirichletBoundarycondition/dirichletBoundarycondition.hpp"
#include "../equation/advectionEquation/advectionEquation.hpp"
#include "../mesh/mesh.hpp"
#include "../parameters/parameters.hpp"
#include "../riemann/upwindRiemann/upwindRiemann.hpp"
#include "../timediscretization/eulerForwardTimeDiscretization/eulerForwardTimeDiscretization.hpp"
#include <memory>
#include <vector>

class Simulator;

class SimulationBuilder
{
public:
    SimulationBuilder& configureMesh(unsigned int numberOfCells,
                                     float leftBoundary, float rightBoundary);
    SimulationBuilder&
    configureBoundarycondition(Parameters::Boundarycondition boundarycondition);
    SimulationBuilder&
    configureInitialcondition(Parameters::Initialcondition initalcondition);
    SimulationBuilder&
    configureEquation(Parameters::Equation::Equations equation);
    SimulationBuilder&
    configureRiemannSolver(Parameters::RiemannSolver riemann);
    SimulationBuilder&
        configureTimeDiscretization(Parameters::TimeDiscretization);
    Simulator createSimulator() const;

private:
    std::vector<float> m_solution;
    Mesh m_mesh;
    unsigned int m_numberOfTimesteps;
    std::shared_ptr<AbstractEquation> m_equation;
    std::shared_ptr<AbstractRiemann> m_riemannSolver;
    std::shared_ptr<AbstractBoundarycondition> m_boundarycondition;
    std::shared_ptr<AbstractTimeDiscretization> m_timeDiscretization{};
};
#endif // SIMULATIONBUILDER_HPP