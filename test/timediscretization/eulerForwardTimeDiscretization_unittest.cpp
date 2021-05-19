#include "../../src/timediscretization/eulerForwardTimeDiscretization/eulerForwardTimeDiscretization.hpp"
#include "../../src/timediscretization/timeDiscretizationInterface.hpp"
#include "gmock/gmock.h"

using namespace ::testing;

class RightHandSideMock : public TimeDiscretizationInterface
{
public:
    MOCK_METHOD(std::vector<float>, computeRightHandSide,
                (const std::vector<float>& solutionVector), (override));
};

class EulerForwardTest : public Test
{
protected:
    float m_testDeltaT = 0.1;
};

TEST_F(EulerForwardTest, PerformOneEulerTimeStepWhenRightHandSideIsIdentity)
{
    std::vector<float> solutionVector{1.};
    auto expectedSolution =
        solutionVector[0] + m_testDeltaT * solutionVector[0];

    auto rhs_mock = std::make_unique<RightHandSideMock>();
    EXPECT_CALL(*rhs_mock, computeRightHandSide(solutionVector));
    ON_CALL(*rhs_mock, computeRightHandSide(solutionVector))
        .WillByDefault(Invoke(
            [](std::vector<float> solutionVector) { return solutionVector; }));

    EulerForwardTimeDiscretization m_testEulerForwardTimeDisc(
        m_testDeltaT, std::move(rhs_mock));
    m_testEulerForwardTimeDisc.timestep(solutionVector);

    ASSERT_THAT(solutionVector, Each(expectedSolution));
}