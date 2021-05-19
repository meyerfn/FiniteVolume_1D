ADD_LIBRARY(Riemann)
target_sources(Riemann
    PRIVATE
        upwindRiemann.cpp
        upwindRiemann.hpp
)
target_link_libraries(Riemann AdvectionEquation)