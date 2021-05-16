#include "mesh.hpp"
#include <cassert>
#include <iostream>
#define assertm(exp, msg) assert(((void)msg, exp))

Mesh::Mesh(unsigned int numberOfCells, float leftBoundary, float rightBoundary)
    : m_numberOfCells(numberOfCells), m_leftBoundary(leftBoundary),
      m_rightBoundary(rightBoundary)
{
    assertm(m_leftBoundary < m_rightBoundary,
            "Left boundary has to be smaller than right boundary");
    m_meshWidth = (m_rightBoundary - m_leftBoundary) / m_numberOfCells;
    createMidPointsOfMesh();
    createGhostPoints();
}

void Mesh::createMidPointsOfMesh()
{
    m_midPointMesh.push_back(m_leftBoundary + m_meshWidth / 2.);
    for (size_t i = 1; i < m_numberOfCells; ++i)
    {
        m_midPointMesh.push_back(m_leftBoundary + m_meshWidth * i +
                                 m_meshWidth / 2.);
    }
}

void Mesh::createGhostPoints()
{
    m_ghostPoints.push_back(m_leftBoundary - m_meshWidth / 2.);
    m_ghostPoints.push_back(m_rightBoundary + m_meshWidth / 2.);
}
