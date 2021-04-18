ADD_LIBRARY(BoundaryConditions)
target_sources(BoundaryConditions
    PRIVATE
    dirichletBoundaryCondition.cpp
    dirichletBoundaryCondition.hpp
    abstractBoundaryCondition.hpp
)