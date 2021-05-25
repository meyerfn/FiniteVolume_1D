#include "../../src/initialcondition/initialcondition.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class InitialConditionTest : public Test
{
public:
    void SetUp() override
    {
        float meshwidth = 1. / m_testNumberOfMeshpoints;
        for (int i = 0; i < m_testNumberOfMeshpoints; ++i)
        {
            m_testMeshpoints[i] = (i * meshwidth);
        }
    }
    static constexpr int m_testNumberOfMeshpoints = 10;
    std::vector<float> m_testMeshpoints =
        std::vector<float>(m_testNumberOfMeshpoints, 0.);
};

TEST_F(InitialConditionTest, CorrectInitializationOfRectangularPulse)
{
    InitialCondition ic{};
    auto initialcondition = ic.rectangularPulse(m_testMeshpoints);

    std::vector<float> expectedResult = {0., 0., 1., 1., 1.,
                                         1., 0., 0., 0., 0.};

    ASSERT_THAT(initialcondition, ElementsAreArray(expectedResult));
};