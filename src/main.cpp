#include "boundaryCondition/dirichletBoundaryCondition.hpp"
#include "mesh/mesh.hpp"
#include "parameters/parameters.hpp"
#include "riemann/upwindRiemann.hpp"
#include "timediscretization/eulerForwardTimeDiscretization.hpp"

int main()
{
    Mesh mesh(Parameters::SimulationParameters::numberOfCells,
              Parameters::SimulationParameters::leftBoundary,
              Parameters::SimulationParameters::rightBoundary);
    DirichletBoundaryCondition bc{};
    auto riemann = std::make_unique<UpwindRiemann>(Parameters::EquationParameters::advectionVelocity,
                          std::make_unique<DirichletBoundaryCondition>(bc));
    EulerForwardTimeDiscretization timeDiscretization(
        Parameters::SimulationParameters::determineDeltaT(),
        std::move(riemann));
}