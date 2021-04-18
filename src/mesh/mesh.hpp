#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
class Mesh
{
public:
    Mesh(unsigned int numberOfCells, float leftBoundary, float rightBoundary);
    float getMeshWidth() const
    {
        return h;
    }
    std::vector<float> getMeshPoints() const
    {
        return meshPoints;
    }

private:
    void createMeshPoints();
    void createGhostPoints();
    float numberOfCells;
    float leftBoundary;
    float rightBoundary;
    float h;
    std::vector<float> meshPoints;
    std::vector<float> ghostPoints;
};

#endif //MESH_HPP