#include "../../src/boundarycondition/dirichletBoundarycondition/dirichletBoundarycondition.hpp"
#include "../../src/equation/advectionEquation/advectionEquation.hpp"
#include "../../src/riemann/upwindRiemann/upwindRiemann.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class UpwindRiemannTest : public Test
{
public:
    std::vector<float> m_testLeftBoundaryValue = std::vector<float>(20, 2.);
    std::vector<float> m_testRightBoundaryValue = std::vector<float>(20, 0.);
};

TEST_F(UpwindRiemannTest, CorrectNumericalFluxForPositiveAdvectionVelocity)
{
    AdvectionEquation m_testAdvectionEquation{1.};
    UpwindRiemann m_testUpwind{
        std::make_unique<AdvectionEquation>(m_testAdvectionEquation)};

    std::vector<float> numericalFlux = m_testUpwind.numericalFlux(
        m_testLeftBoundaryValue, m_testRightBoundaryValue);

    std::vector<float> expectedFlux(m_testLeftBoundaryValue);
    std::transform(expectedFlux.begin(), expectedFlux.end(),
                   expectedFlux.begin(),
                   [&m_testAdvectionEquation](auto& elem) {
                       return elem * m_testAdvectionEquation.getSignalSpeed();
                   });

    ASSERT_THAT(numericalFlux, ElementsAreArray(expectedFlux));
};

TEST_F(UpwindRiemannTest, CorrectNumericalFluxForNegativeAdvectionVelocity)
{
    AdvectionEquation m_testAdvectionEquation{-1.};
    UpwindRiemann m_testUpwind{
        std::make_unique<AdvectionEquation>(m_testAdvectionEquation)};

    std::vector<float> numericalFlux = m_testUpwind.numericalFlux(
        m_testLeftBoundaryValue, m_testRightBoundaryValue);

    std::vector<float> expectedFlux(m_testRightBoundaryValue);
    std::transform(expectedFlux.begin(), expectedFlux.end(),
                   expectedFlux.begin(),
                   [&m_testAdvectionEquation](auto& elem) {
                       return elem * m_testAdvectionEquation.getSignalSpeed();
                   });

    ASSERT_THAT(numericalFlux, ElementsAreArray(expectedFlux));
};