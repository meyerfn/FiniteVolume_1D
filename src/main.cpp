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
        Parameters::EquationParameters::advectionVelocity, mesh.getMeshWidth(),
        std::make_unique<DirichletBoundarycondition>(bc));
    EulerForwardTimeDiscretization timeDiscretization(
        Parameters::SimulationParameters::determineDeltaT(),
        Parameters::SimulationParameters::determineNumberOfTimesteps(),
        std::move(riemann));
    auto solution =
        InitialCondition::rectangularPulse(mesh.getMidPointsOfMesh());
    auto numberOfTimesteps = timeDiscretization.getNumberOfTimesteps();
    for (int i = 0; i < timeDiscretization.getNumberOfTimesteps(); ++i)
    {
        timeDiscretization.timestep(solution);
    }
    auto test = solution;
}