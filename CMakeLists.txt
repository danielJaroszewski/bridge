cmake_minimum_required(VERSION 3.1)
project(most)

find_package(Catch2 REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED) # This is NOT a redundancy, for some reason ImGui-SFML doesn't load imgui package.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

set(CXX_STANDARD 14)

file(GLOB_RECURSE SRC1 ./src/*.cpp)
add_library(most-core STATIC ${SRC1})
target_link_libraries(most-core PUBLIC box2d::box2d sfml-system sfml-network sfml-graphics sfml-window ImGui-SFML::ImGui-SFML)

add_executable(most main.cpp)
target_link_libraries(most PRIVATE most-core)

add_executable(test ./tests/test.cpp)
target_link_libraries(test PRIVATE most-core Catch2::Catch2WithMain)

add_executable(graphicTest ./tests/graphicTests.cpp)
target_link_libraries(graphicTest PRIVATE most-core Catch2::Catch2WithMain)