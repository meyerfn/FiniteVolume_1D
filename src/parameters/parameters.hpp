#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
namespace Parameters
{
enum class BoundaryConditions
{
    Dirichlet,
    Upwind
};
namespace EquationParameters
{
static constexpr float advectionVelocity = 1.;
};
namespace SimulationParameters
{
static constexpr float leftBoundary = 0.;
static constexpr float rightBoundary = 2.;
static constexpr unsigned int numberOfCells = 512;
static constexpr float finalComputationTime = 1.0;

constexpr float determineDeltaT()
{
    return EquationParameters::advectionVelocity * (1. / numberOfCells);
}
constexpr unsigned int determineNumberOfTimesteps()
{
    return finalComputationTime / determineDeltaT();
}
}; // namespace SimulationParameters

} // namespace Parameters
#endif // PARAMETERS_HPP