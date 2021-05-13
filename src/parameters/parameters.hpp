#ifndef PARAMETERS_HPP
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
static constexpr float rightBoundary = 1.;
static constexpr float leftBoundary = 0.;
static constexpr unsigned int numberOfCells = 128;
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
#define PARAMETERS_HPP
#endif // PARAMETERS_HPP