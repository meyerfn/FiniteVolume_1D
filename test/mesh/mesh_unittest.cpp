#include "../../src/mesh/mesh.hpp"
#include "gmock/gmock.h"

using namespace ::testing;

class MeshTest : public Test
{
protected:
    void fillExpectedMeshPoints()
    {
        auto h = (rightBoundary - leftBoundary) / numberOfCells;
        for (size_t i = 0; i < numberOfCells; ++i)
        {
            expectedMeshPoints.push_back(leftBoundary + h / 2. + (h * i));
        }
    }
    unsigned int numberOfCells = 20U;
    float leftBoundary = 0.;
    float rightBoundary = 1.;
    std::vector<float> expectedMeshPoints{};
};

TEST_F(MeshTest, MeshWidthIsCorrectlyComputed)
{
    auto expectedMeshWidth = 1. / 20;

    Mesh mesh{numberOfCells, leftBoundary, rightBoundary};

    ASSERT_THAT(mesh.getMeshWidth(), FloatEq(expectedMeshWidth));
};

TEST_F(MeshTest, MidPointsOfMeshAreCorrectlyComputed)
{
    fillExpectedMeshPoints();

    Mesh mesh{numberOfCells, leftBoundary, rightBoundary};

    ASSERT_THAT(mesh.getMidPointsOfMesh(),
                ElementsAreArray(expectedMeshPoints));
};
