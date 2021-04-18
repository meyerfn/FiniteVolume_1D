add_executable(TimeDiscretization_Unittest)
target_sources(TimeDiscretization_Unittest
    PRIVATE
    eulerForwardTimeDiscretization_unittest.cpp
)
target_link_libraries(TimeDiscretization_Unittest gmock gmock_main TimeDiscretization)
