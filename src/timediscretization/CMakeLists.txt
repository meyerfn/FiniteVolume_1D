ADD_LIBRARY(TimeDiscretization)
target_sources(TimeDiscretization
    PRIVATE
    eulerForwardTimeDiscretization.hpp
    eulerForwardTimeDiscretization.cpp
    abstractTimeDiscretization.cpp
    abstractTimeDiscretization.hpp
)
target_link_libraries(TimeDiscretization Riemann Boundaryconditions) 