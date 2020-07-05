cmake_minimum_required(VERSION 3.16)
project(adventOfCode)


set(CMAKE_CXX_STANDARD 14)

# add the MathFunctions library
add_subdirectory(Day1)

add_executable(adventOfCode main.cpp)

target_link_libraries(adventOfCode PUBLIC Day1)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(adventOfCode PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Day1"
        )