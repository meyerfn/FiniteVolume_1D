#include "simulationBuilder.hpp"
#include "../../src/initialcondition/initialcondition.hpp"
#include "../../src/surfaceintegral/surfaceintegral.hpp"
#include "simulator.hpp"

using namespace Parameters::Equation;
using namespace Parameters;

SimulationBuilder& SimulationBuilder::configureMesh(unsigned int numberOfCells,
                                                    float leftBoundary,
                                                    float rightBoundary)
{
    m_mesh = Mesh{numberOfCells, leftBoundary, rightBoundary};
    return *this;
}

SimulationBuilder& SimulationBuilder::configureBoundarycondition(
    Boundarycondition boundarycondition)
{
    if (boundarycondition == Boundarycondition::Dirichlet)
    {
        m_boundarycondition = std::make_shared<DirichletBoundarycondition>();
    }
    return *this;
}

SimulationBuilder&
SimulationBuilder::configureInitialcondition(Initialcondition initialcondition)
{
    if (initialcondition == Initialcondition::RectangularPulse)
    {
        m_solution =
            ::InitialCondition::rectangularPulse(m_mesh.getMidPointsOfMesh());
    }
    return *this;
}

SimulationBuilder& SimulationBuilder::configureEquation(Equations equation)
{
    if (equation == Equations::LinearAdvection)
    {
        m_equation = std::make_shared<AdvectionEquation>(
            Parameters::Equation::LinearAdvectionParameters::advectionVelocity);
    }
    return *this;
}

SimulationBuilder&
SimulationBuilder::configureRiemannSolver(Parameters::RiemannSolver riemann)
{
    if (riemann == Parameters::RiemannSolver::Upwind)
    {
        m_riemannSolver = std::make_shared<UpwindRiemann>(m_equation);
    }
    return *this;
}

SimulationBuilder& SimulationBuilder::configureTimeDiscretization(
    TimeDiscretization timeDiscretization)
{
    const auto surfaceintegral = std::make_shared<Surfaceintegral>(
        m_mesh.getMeshWidth(), m_riemannSolver, m_boundarycondition);
    const float timeStepSize =
        SimulationParameters::determineDeltaT(m_equation->getSignalSpeed());
    const unsigned int numberOfTimesteps =
        SimulationParameters::determineNumberOfTimesteps(timeStepSize);

    if (timeDiscretization == TimeDiscretization::ForwardEuler)
    {
        m_timeDiscretization = std::make_shared<EulerForwardTimeDiscretization>(
            timeStepSize, numberOfTimesteps, surfaceintegral);
    }
    return *this;
}

Simulator SimulationBuilder::createSimulator() const
{
    const Simulator simulator{m_timeDiscretization, m_solution};
    return simulator;
}