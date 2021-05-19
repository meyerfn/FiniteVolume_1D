add_subdirectory(${TEST_DIR}/initialcondition)
add_subdirectory(${TEST_DIR}/mesh)
add_subdirectory(${TEST_DIR}/riemann)
add_subdirectory(${TEST_DIR}/surfaceintegral)
add_subdirectory(${TEST_DIR}/timediscretization)
add_executable(All_Unittests)
target_sources(All_Unittests
                PRIVATE 
                initialcondition/initialcondition_unittest.cpp
                mesh/mesh_unittest.cpp
                riemann/upwindRiemann_unittest.cpp
                surfaceintegral/surfaceintegral_unittest.cpp
                timediscretization/eulerForwardTimeDiscretization_unittest.cpp
                )
target_link_libraries(All_Unittests Initialcondition Mesh Riemann Surfaceintegral 
                        TimeDiscretization gmock gmock_main)