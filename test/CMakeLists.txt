ADD_SUBDIRECTORY(${TEST_DIR}/mesh)
ADD_SUBDIRECTORY(${TEST_DIR}/riemann)
# ADD_SUBDIRECTORY(${TEST_DIR}/timediscretization)
add_executable(All_Unittests)
target_sources(All_Unittests
PRIVATE 
mesh/mesh_unittest.cpp
riemann/upwindRiemann_unittest.cpp
# timediscretization/eulerForwardTimeDiscretization_unittest.cpp
)
target_link_libraries(All_Unittests Mesh Riemann TimeDiscretization gmock gmock_main)