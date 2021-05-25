add_executable(Surfaceintegral_Unittest)
target_sources(Surfaceintegral_Unittest
    PRIVATE
        surfaceintegral_unittest.cpp
)
target_link_libraries(Surfaceintegral_Unittest gmock gmock_main
                        Surfaceintegral Riemann AdvectionEquation Boundarycondition)
