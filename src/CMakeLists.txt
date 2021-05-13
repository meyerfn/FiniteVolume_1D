add_subdirectory(${SOURCE_DIR}/mesh)
add_subdirectory(${SOURCE_DIR}/riemann)
add_subdirectory(${SOURCE_DIR}/boundarycondition)
add_subdirectory(${SOURCE_DIR}/timediscretization)
add_subdirectory(${SOURCE_DIR}/initialcondition)

add_executable(main main.cpp)
target_link_libraries(main Mesh Riemann Boundaryconditions Initialcondition TimeDiscretization )