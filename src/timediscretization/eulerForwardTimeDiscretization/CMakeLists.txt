add_library(TimeDiscretization)
target_sources(TimeDiscretization
    PRIVATE
    eulerForwardTimeDiscretization.hpp
    eulerForwardTimeDiscretization.cpp
)