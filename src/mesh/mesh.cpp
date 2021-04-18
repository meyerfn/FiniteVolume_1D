#include "mesh.hpp"
#include <cassert>
#include <iostream>
#define assertm(exp, msg) assert(((void)msg, exp))

Mesh::Mesh(unsigned int numberOfCells, float leftBoundary, float rightBoundary) : numberOfCells(numberOfCells), leftBoundary(leftBoundary), rightBoundary(rightBoundary)
{
    assertm(leftBoundary < rightBoundary, "Left boundary has to be smaller than right boundary");
    h = (rightBoundary - leftBoundary) / numberOfCells;
    createMeshPoints();
    createGhostPoints();
}

void Mesh::createMeshPoints()
{
    for (size_t i = 0; i < numberOfCells; ++i)
    {
        meshPoints.push_back(leftBoundary + h * i);
    }
}

void Mesh::createGhostPoints(){
    ghostPoints.push_back(leftBoundary - h);
    ghostPoints.push_back(rightBoundary + h);
}

