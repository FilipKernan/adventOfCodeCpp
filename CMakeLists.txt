cmake_minimum_required(VERSION 3.16)
project(adventOfCode)


set(CMAKE_CXX_STANDARD 14)

# add the MathFunctions library
add_subdirectory(Fuel)
add_subdirectory(Intcode)
add_subdirectory(ReadFile)
add_subdirectory(Wires)
add_subdirectory(Numbers)
add_subdirectory(Orbits)






add_executable(adventOfCode main.cpp)

target_link_libraries(adventOfCode PUBLIC Fuel Intcode ReadFile Wires Numbers Orbits)

# add the binary tree to the search path for include files

target_include_directories(adventOfCode PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/Fuel"
        "${PROJECT_SOURCE_DIR}/Intcode"
        "${PROJECT_SOURCE_DIR}/ReadFile"
        "${PROJECT_SOURCE_DIR}/Wires"
        "${PROJECT_SOURCE_DIR}/Numbers"
        "${PROJECT_SOURCE_DIR}/Orbits"

        )