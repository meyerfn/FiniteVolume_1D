#include "../../src/boundarycondition/dirichletBoundarycondition/dirichletBoundarycondition.hpp"
#include "../../src/equation/advectionEquation/advectionEquation.hpp"
#include "../../src/riemann/upwindRiemann/upwindRiemann.hpp"
#include "../../src/surfaceintegral/surfaceintegral.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class SurfaceintegralTest : public Test
{
public:
    float m_testMeshWidth{0.5};
    float m_testAdvectionVelocity{1.};
    std::unique_ptr<DirichletBoundarycondition> m_testBc =
        std::make_unique<DirichletBoundarycondition>();
    std::unique_ptr<AdvectionEquation> m_testEquation =
        std::make_unique<AdvectionEquation>(1.);
    std::unique_ptr<UpwindRiemann> m_testRiemann =
        std::make_unique<UpwindRiemann>(std::move(m_testEquation));
    Surfaceintegral m_testsurfaceintegral{
        m_testMeshWidth, std::move(m_testRiemann), std::move(m_testBc)};
};

TEST_F(SurfaceintegralTest, IfSolutionIsZeroSurfaceIntegralIsZero)
{
    std::vector<float> solution(20, 0.);
    auto surfaceintegral =
        m_testsurfaceintegral.computeSurfaceintegral(solution);

    ASSERT_THAT(surfaceintegral, Each(0.));
}

TEST_F(SurfaceintegralTest, CorrectComputationOfSurfaceintegralForUpwindFlux)
{
    std::vector<float> solution(20, 0.);
    std::iota(begin(solution), end(solution), 1);
    // upwind flux differences are equal to -1
    std::vector<float> expectedSurfaceIntegral(20, -1.);
    std::transform(
        expectedSurfaceIntegral.begin(), expectedSurfaceIntegral.end(),
        expectedSurfaceIntegral.begin(), [this](auto& elem) {
            return elem * m_testAdvectionVelocity * (1. / m_testMeshWidth);
        });

    auto surfaceintegral =
        m_testsurfaceintegral.computeSurfaceintegral(solution);

    ASSERT_THAT(surfaceintegral, ElementsAreArray(expectedSurfaceIntegral));
}
