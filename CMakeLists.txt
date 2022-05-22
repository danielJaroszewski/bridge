cmake_minimum_required(VERSION 3.1)
project(most)

find_package(Catch2 3 REQUIRED HINTS /usr/local/include)
find_package(box2d CONFIG REQUIRED)

set(CXX_STANDARD 11)


file(GLOB_RECURSE SRC1 ./src/*.cpp)
add_library(most-core STATIC ${SRC1})
target_link_libraries(most-core PUBLIC box2d::box2d)

add_executable(most main.cpp)
target_link_libraries(most PRIVATE most-core)

add_executable(test ./tests/test.cpp ${SRC2})

target_link_libraries(test PRIVATE most-core Catch2::Catch2WithMain)
