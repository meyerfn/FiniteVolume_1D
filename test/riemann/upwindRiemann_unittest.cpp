#include "../../src/boundarycondition/dirichletBoundarycondition.hpp"
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

    int m_testNumberOfCells = 20;
    std::vector<float> m_testSolution =
        std::vector<float>(m_testNumberOfCells, 0.);
    DirichletBoundarycondition m_testDirichlet{};
    const float m_testAdvectionVelocity = 1.;
    const float m_testMeshWidth = 0.5;
    UpwindRiemann m_testUpwind{
        m_testAdvectionVelocity, m_testMeshWidth,
        std::make_unique<DirichletBoundarycondition>(m_testDirichlet)};
};

TEST_F(UpwindRiemannTest, IfZeroSolutionFluxIsZero)
{
    std::vector<float> numericalFlux =
        m_testUpwind.computeSurfaceIntegral(m_testSolution);
    ASSERT_THAT(numericalFlux, ElementsAreArray(m_testSolution));
};

TEST_F(UpwindRiemannTest, CorrectFluxWithCorrectDirichletBoundaryCondition)
{
    fillSolutionWithIncreasingNumbers();
    std::vector<float> numericalFlux =
        m_testUpwind.computeSurfaceIntegral(m_testSolution);

    std::vector<float> expectedFlux(m_testNumberOfCells, -1.);
    std::transform(expectedFlux.begin(), expectedFlux.end(),
                   expectedFlux.begin(), [this](auto& elem) {
                       return elem * m_testAdvectionVelocity * m_testMeshWidth;
                   });

    ASSERT_THAT(numericalFlux, ElementsAreArray(expectedFlux));
};
