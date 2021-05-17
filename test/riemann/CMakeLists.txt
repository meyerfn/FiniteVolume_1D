add_executable(Riemann_Unittest)
target_sources(Riemann_Unittest
    PRIVATE
        upwindRiemann_unittest.cpp
)
target_link_libraries(Riemann_Unittest gmock gmock_main Riemann Surfaceintegral)
