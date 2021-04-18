cmake_minimum_required(VERSION 3.14)

# set the project name
project(FV1d)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# specify some helper variables
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")
# add subdirectories
add_subdirectory(${SOURCE_DIR})
add_subdirectory(${LIB_DIR})
add_subdirectory(${TEST_DIR})