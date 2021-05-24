#ifndef MESH_HPP
#define MESH_HPP
#include <vector>
class Mesh
{
public:
    Mesh() = default;
    Mesh(unsigned int numberOfCells, float leftBoundary, float rightBoundary);
    float getMeshWidth() const { return m_meshWidth; }
    std::vector<float> getMidPointsOfMesh() const { return m_midPointMesh; }

private:
    void createMidPointsOfMesh();
    void createGhostPoints();
    float m_numberOfCells;
    float m_leftBoundary;
    float m_rightBoundary;
    float m_meshWidth;
    std::vector<float> m_midPointMesh;
    std::vector<float> m_ghostPoints;
};

#endif // MESH_HPP