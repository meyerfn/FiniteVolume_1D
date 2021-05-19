#include "boundarycondition/dirichletBoundarycondition/dirichletBoundarycondition.hpp"
#include "equation/advectionEquation/advectionEquation.hpp"
#include "initialcondition/initialcondition.hpp"
#include "mesh/mesh.hpp"
#include "parameters/parameters.hpp"
#include "riemann/upwindRiemann/upwindRiemann.hpp"
#include "surfaceintegral/surfaceintegral.hpp"
#include "timediscretization/eulerForwardTimeDiscretization/eulerForwardTimeDiscretization.hpp"
#include <fstream>
#include <string>
int main()
{
    Mesh mesh(Parameters::SimulationParameters::numberOfCells,
              Parameters::SimulationParameters::leftBoundary,
              Parameters::SimulationParameters::rightBoundary);
    auto bc = std::make_unique<DirichletBoundarycondition>();
    auto riemann = std::make_unique<UpwindRiemann>(
        std::unique_ptr<AdvectionEquation>(new AdvectionEquation(1.0)));
    auto surfaceintegral = std::make_unique<Surfaceintegral>(
        mesh.getMeshWidth(),
        std::make_unique<UpwindRiemann>(
            std::unique_ptr<AdvectionEquation>(new AdvectionEquation(1.0))),
        std::make_unique<DirichletBoundarycondition>());
    EulerForwardTimeDiscretization timeDiscretization(
        Parameters::SimulationParameters::determineDeltaT(),
        std::move(surfaceintegral));
    auto solution =
        InitialCondition::rectangularPulse(mesh.getMidPointsOfMesh());
    auto numberOfTimesteps =
        Parameters::SimulationParameters::determineNumberOfTimesteps();
    for (int i = 0; i < numberOfTimesteps; ++i)
    {
        timeDiscretization.timestep(solution);
    }
    std::ofstream file;
    file.open("example.txt", std::fstream::out);
    for (int i = 0; i < solution.size(); ++i)
    {
        file << solution[i] << std::endl;
    }
    file.close();
}