#include "../../src/initialcondition/initialcondition.hpp"
#include "gmock/gmock.h"
#include <numeric>

using namespace ::testing;

class InitialConditionTest : public Test
{
public:
    void SetUp() override
    {
        float meshwidth = 0.25F;
        for (int i = 0; i < numberOfMeshpoints; ++i)
        {
            meshpoints[i] = (i * meshwidth);
        }
    }
    static constexpr int numberOfMeshpoints = 5;
    std::vector<float> meshpoints = std::vector<float>(numberOfMeshpoints, 0.F) ;
};

TEST_F(InitialConditionTest, TEST)
{
    InitialCondition ic{};
    auto initialcondition = ic.rectangularPulse(meshpoints);

    std::vector<float> expectedResult = {0.F, 1.F, 0.F, 0.F, 0.F};

    ASSERT_THAT(initialcondition, ElementsAreArray(expectedResult));
};