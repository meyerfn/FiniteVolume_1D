add_library(Simulator)
target_sources(Simulator
    PRIVATE
        simulationBuilder.hpp
        simulationBuilder.cpp
        simulator.hpp
        simulator.cpp
)
target_link_libraries(Simulator Mesh Boundarycondition 
                        AdvectionEquation Surfaceintegral TimeDiscretization
                        Initialcondition Riemann)