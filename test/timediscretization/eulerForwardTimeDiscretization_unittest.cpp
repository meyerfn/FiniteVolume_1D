#include "../../src/boundarycondition/dirichletBoundarycondition.hpp"
#include "../../src/timediscretization/eulerForwardTimeDiscretization.hpp"
#include "gmock/gmock.h"

using namespace ::testing;

class RiemannMock : public AbstractRiemann
{
public:
    RiemannMock()
        : AbstractRiemann(1.0F, 0.5F,
                          std::make_unique<DirichletBoundarycondition>()){};
    MOCK_METHOD(std::vector<float>, numericalFlux,
                (const std::vector<float>& solutionVector,
                 const std::vector<float>& solutionVector),
                (override));
};

class EulerForwardTest : public Test
{
protected:
    float m_testDeltaT = 0.1F;
    unsigned int m_testNumberOfTimesteps = 10;
};

TEST_F(EulerForwardTest, PerformOneTimeStep)
{
    auto riemann = std::make_unique<RiemannMock>();
    std::vector<float> solutionVector{1.};
    auto expectedSolution =
        solutionVector[0] + m_testDeltaT * solutionVector[0];

    ON_CALL(*riemann, numericalFlux(solutionVector, solutionVector))
        .WillByDefault(Invoke(
            [](std::vector<float> solutionVector) { return solutionVector; }));

    EulerForwardTimeDiscretization m_testEulerForwardTimeDisc(
        m_testDeltaT, m_testNumberOfTimesteps, std::move(riemann));
    m_testEulerForwardTimeDisc.timestep(solutionVector);

    ASSERT_THAT(solutionVector, Each(expectedSolution));
}