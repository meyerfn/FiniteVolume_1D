ADD_LIBRARY(Surfaceintegral)
target_sources(Surfaceintegral
    PRIVATE
        surfaceintegral.cpp
        surfaceintegral.hpp
)
target_link_libraries(Surfaceintegral Boundarycondition Riemann)