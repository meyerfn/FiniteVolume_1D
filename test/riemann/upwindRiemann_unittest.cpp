#include "../../src/boundaryCondition/dirichletBoundaryCondition.hpp"
#include "../../src/riemann/upwindRiemann.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class UpwindRiemannTest : public Test
{
public:
    void SetUp() { solution = std::vector<float>(numberOfCells, 0.); }
    void fillVectorWithIncreasingNumbers()
    {
        std::iota(solution.begin(), solution.end(), 1.);
    }

    int numberOfCells = 20;
    std::vector<float> solution;
    DirichletBoundaryCondition dirichlet{};
    const float advectionVelocity = 1.;
    UpwindRiemann upwind{
        advectionVelocity,
        std::make_unique<DirichletBoundaryCondition>(dirichlet)};
};

TEST_F(UpwindRiemannTest, IfZeroSolutionFluxIsZero)
{
    std::vector<float> numericalFlux = upwind.computeFlux(solution);
    ASSERT_THAT(numericalFlux, ElementsAreArray(solution));
};

TEST_F(UpwindRiemannTest, CorrectFluxWithCorrectDirichletBoundaryCondition)
{
    fillVectorWithIncreasingNumbers();
    std::vector<float> numericalFlux = upwind.computeFlux(solution);

    std::vector<float> expectedFlux(numberOfCells, 0.);
    std::iota(expectedFlux.begin(), expectedFlux.end(), 1.);
    expectedFlux[0]= 0.;
    expectedFlux[numberOfCells -1 ]= 0.;

    ASSERT_THAT(numericalFlux, ElementsAreArray(expectedFlux));
};
