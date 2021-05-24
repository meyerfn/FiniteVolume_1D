#include "parameters/parameters.hpp"
#include "simulator/simulator.hpp"

using namespace Parameters;

int main()
{
    auto simulator =
        Simulator::make()
            .configureMesh(SimulationParameters::numberOfCells,
                           SimulationParameters::leftBoundary,
                           SimulationParameters::rightBoundary)
            .configureBoundarycondition(Boundarycondition::Dirichlet)
            .configureInitialcondition(Initialcondition::RectangularPulse)
            .configureEquation(Equation::Equations::LinearAdvection)
            .configureRiemannSolver(RiemannSolver::Upwind)
            .configureTimeDiscretization(
                Parameters::TimeDiscretization::ForwardEuler)
            .createSimulator();
    simulator.runSimulation();
}