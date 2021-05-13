#include "boundarycondition/dirichletBoundarycondition.hpp"
#include "initialcondition/initialcondition.hpp"
#include "mesh/mesh.hpp"
#include "parameters/parameters.hpp"
#include "riemann/upwindRiemann.hpp"
#include "timediscretization/eulerForwardTimeDiscretization.hpp"

int main()
{
    Mesh mesh(Parameters::SimulationParameters::numberOfCells,
              Parameters::SimulationParameters::leftBoundary,
              Parameters::SimulationParameters::rightBoundary);
    DirichletBoundarycondition bc{};
    auto riemann = std::make_unique<UpwindRiemann>(
        Parameters::EquationParameters::advectionVelocity,
        std::make_unique<DirichletBoundarycondition>(bc));
    EulerForwardTimeDiscretization timeDiscretization(
        Parameters::SimulationParameters::determineDeltaT(),
        Parameters::SimulationParameters::determineNumberOfTimesteps(),
        std::move(riemann));
    auto solution =
        InitialCondition::rectangularPulse(mesh.getMidPointsOfMesh());
    for (int i = 0; i < 100; ++i)
    {
        timeDiscretization.timestep(solution);
    }
    auto test = solution;
}