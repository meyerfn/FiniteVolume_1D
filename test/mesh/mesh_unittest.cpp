#include "gmock/gmock.h"
#include "../../src/mesh/mesh.hpp"

using namespace ::testing;

class MeshTest : public Test
{
protected:
    void fillExpectedMeshPoints()
    {
        auto h = (rightBoundary - leftBoundary) / numberOfCells;
        for (size_t i = 0; i < numberOfCells; ++i)
        {
            expectedMeshPoints.push_back(leftBoundary + h * i);
        }
    }
    unsigned int numberOfCells = 20U;
    float leftBoundary = 0.;
    float rightBoundary = 1.;
    std::vector<float> expectedMeshPoints{};
};

TEST_F(MeshTest, IfMeshWidthIsCorrectlyComputed)
{
    auto expectedH = 1. / 20;
    Mesh mesh{numberOfCells, leftBoundary, rightBoundary};
    ASSERT_THAT(mesh.getMeshWidth(), FloatEq(expectedH));
};

TEST_F(MeshTest, IfMeshPointsAreComputedCorrectly)
{
    fillExpectedMeshPoints();
    Mesh mesh{numberOfCells, leftBoundary, rightBoundary};
    ASSERT_THAT(mesh.getMeshPoints(), ElementsAreArray(expectedMeshPoints));
};
