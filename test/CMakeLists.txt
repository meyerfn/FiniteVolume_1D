add_subdirectory(${TEST_DIR}/mesh)
add_subdirectory(${TEST_DIR}/riemann)
add_subdirectory(${TEST_DIR}/timediscretization)
add_subdirectory(${TEST_DIR}/initialcondition)
add_executable(All_Unittests)
target_sources(All_Unittests
                PRIVATE 
                mesh/mesh_unittest.cpp
                riemann/upwindRiemann_unittest.cpp
                timediscretization/eulerForwardTimeDiscretization_unittest.cpp
                initialcondition/initialcondition_unittest.cpp
                )
target_link_libraries(All_Unittests Mesh Riemann TimeDiscretization Initialcondition gmock gmock_main)