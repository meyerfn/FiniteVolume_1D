add_executable(Mesh_Unittest)
target_sources(Mesh_Unittest
    PRIVATE
        mesh_unittest
)
target_link_libraries(Mesh_Unittest gmock gmock_main Mesh)
