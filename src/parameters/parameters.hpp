#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP
namespace Parameters
{
enum class Initialcondition
{
    RectangularPulse
};
enum class Boundarycondition
{
    Dirichlet,
    Upwind
};
enum class RiemannSolver
{
    Upwind
};
enum class TimeDiscretization
{
    ForwardEuler
};
namespace Equation
{
enum class Equations
{
    LinearAdvection
};
namespace LinearAdvectionParameters
{
static constexpr float advectionVelocity = 1.;
} // namespace LinearAdvectionParameters
} // namespace Equation

namespace SimulationParameters
{
static constexpr float leftBoundary = 0.;
static constexpr float rightBoundary = 2.;
static constexpr unsigned int numberOfCells = 512;
static constexpr float finalComputationTime = 1.0;

constexpr float determineDeltaT(float signalVelocity)
{
    return signalVelocity * (1. / numberOfCells);
}
constexpr unsigned int determineNumberOfTimesteps(float deltaT)
{
    return finalComputationTime / deltaT;
}
} // namespace SimulationParameters
} // namespace Parameters
#endif // PARAMETERS_HPP