ADD_LIBRARY(Boundaryconditions)
target_sources(Boundaryconditions
    PRIVATE
    dirichletBoundarycondition.cpp
    dirichletBoundarycondition.hpp
    abstractBoundarycondition.hpp
)