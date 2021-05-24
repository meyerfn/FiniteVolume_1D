#include "boundarycondition/dirichletBoundarycondition/dirichletBoundarycondition.hpp"
#include "equation/advectionEquation/advectionEquation.hpp"
#include "initialcondition/initialcondition.hpp"
#include "mesh/mesh.hpp"
#include "parameters/parameters.hpp"
#include "riemann/upwindRiemann/upwindRiemann.hpp"
#include "surfaceintegral/surfaceintegral.hpp"
#include "timediscretization/eulerForwardTimeDiscretization/eulerForwardTimeDiscretization.hpp"

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