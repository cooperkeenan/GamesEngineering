cmake_minimum_required(VERSION 3.11)

# Project information
project(Games_Engineering)

# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

# Find and link SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Directories for includes and libraries (if SFML installed via Homebrew)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Practical 1 Target
file(GLOB_RECURSE PRACTICAL_1_SOURCES practical_1/*.cpp practical_1/*.h)
add_executable(PRACTICAL_1 ${PRACTICAL_1_SOURCES})
target_include_directories(PRACTICAL_1 PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(PRACTICAL_1 sfml-graphics sfml-window sfml-system)

# Space Invaders Target
file(GLOB_RECURSE INVADERS_SOURCES 2_invaders/*.cpp 2_invaders/*.h)
add_executable(2_INVADERS ${INVADERS_SOURCES})
target_include_directories(2_INVADERS PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(2_INVADERS sfml-graphics sfml-window sfml-system)

# Tile Engine Target
file(GLOB_RECURSE TILE_ENGINE_SOURCES practical_3/*.cpp practical_3/*.h)
add_executable(PRACTICAL_3 ${TILE_ENGINE_SOURCES})
target_include_directories(PRACTICAL_3 PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(PRACTICAL_3 sfml-graphics sfml-window sfml-system)
