ADD_LIBRARY(TimeDiscretization)
target_sources(TimeDiscretization
    PRIVATE
    eulerForwardTimeDiscretization.hpp
    eulerForwardTimeDiscretization.cpp
)
target_link_libraries(TimeDiscretization Riemann Boundarycondition) 