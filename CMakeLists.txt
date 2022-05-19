cmake_minimum_required(VERSION 3.1)
find_package(Catch2 3 REQUIRED HINTS /usr/local/include)
find_package(box2d CONFIG REQUIRED)

set(CXX_STANDARD 11)

project(most)

file(GLOB_RECURSE SRC1 ./src/*.cpp)

add_executable(most main.cpp ${SRC1})

add_executable(test ./tests/test.cpp ${SRC1} ${SRC2})
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(most PRIVATE box2d::box2d)