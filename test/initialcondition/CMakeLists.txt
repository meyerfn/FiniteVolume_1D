add_executable(Initialcondition_Unittest)
target_sources(Initialcondition_Unittest
    PRIVATE
        initialcondition_unittest.cpp
)
target_link_libraries(Initialcondition_Unittest gmock gmock_main Initialcondition)
