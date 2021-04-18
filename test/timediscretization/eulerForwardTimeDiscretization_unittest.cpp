#include "../../src/timediscretization/eulerForwardTimeDiscretization.hpp"
#include "gmock/gmock.h"

using namespace ::testing;

class RiemannMock : public AbstractRiemann
{
public:
    MOCK_METHOD(std::vector<float>, computeFlux,
                (const std::vector<float>& solutionVector), (override));
};

class EulerForwardTest : public Test
{
protected:
    float m_testDeltaT = 0.1F;
};

TEST_F(EulerForwardTest, PerformOneTimeStep)
{
    auto riemann = std::make_unique<RiemannMock>();
    std::vector<float> solutionVector{1.F};
    auto expectedSolution = solutionVector[0] + 0.1F*solutionVector[0];
    ON_CALL(*riemann, computeFlux(solutionVector))
        .WillByDefault(testing::Invoke(
            [](std::vector<float> solutionVector) { return solutionVector; }));

    EulerForwardTimeDiscretization m_testEulerForwardTimeDisc(
        m_testDeltaT, std::move(riemann));
    m_testEulerForwardTimeDisc.timestep(solutionVector);
    
    ASSERT_THAT(solutionVector, Each(expectedSolution));
}