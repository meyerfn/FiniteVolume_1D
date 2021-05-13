ADD_LIBRARY(Riemann)
target_sources(Riemann
    PRIVATE
        upwindRiemann.cpp
        upwindRiemann.hpp
        abstractRiemann.hpp
)
target_link_libraries(Riemann Boundaryconditions)