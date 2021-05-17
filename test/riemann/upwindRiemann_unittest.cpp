#include "../../src/boundarycondition/dirichletBoundarycondition.hpp"
#include "../../src/equation/advectionEquation/advectionEquation.hpp"
#include "../../src/riemann/upwindRiemann.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class UpwindRiemannTest : public Test
{
public:
    void fillSolutionWithIncreasingNumbers()
    {
        std::iota(m_testSolution.begin(), m_testSolution.end(), 1.);
    }

    const float m_testAdvectionVelocity = 1.;
    int m_testNumberOfCells = 20;
    const float m_testMeshWidth = 0.5;
    std::vector<float> m_testSolution =
        std::vector<float>(m_testNumberOfCells, 0.);
    DirichletBoundarycondition m_testDirichlet{};
    AdvectionEquation m_testAdvectionEquation{m_testAdvectionVelocity};
    UpwindRiemann m_testUpwind{
        std::make_unique<AdvectionEquation>(m_testAdvectionEquation)};
};

TEST_F(UpwindRiemannTest, IfZeroSolutionFluxIsZero)
{
    std::vector<float> numericalFlux =
        m_testUpwind.numericalFlux(m_testSolution, m_testSolution);
    ASSERT_THAT(numericalFlux, ElementsAreArray(m_testSolution));
};

TEST_F(UpwindRiemannTest, CorrectFluxWithCorrectDirichletBoundaryCondition)
{
    fillSolutionWithIncreasingNumbers();
    std::vector<float> numericalFlux =
        m_testUpwind.numericalFlux(m_testSolution, m_testSolution);

    std::vector<float> expectedFlux(m_testNumberOfCells, -1.);
    std::transform(expectedFlux.begin(), expectedFlux.end(),
                   expectedFlux.begin(), [this](auto& elem) {
                       return elem * m_testAdvectionVelocity *
                              (1. / m_testMeshWidth);
                   });

    ASSERT_THAT(numericalFlux, ElementsAreArray(expectedFlux));
};
