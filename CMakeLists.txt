cmake_minimum_required(VERSION 3.14)
project(Sem2_contest3_2a)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall")
set(GOOGLETEST_VERSION 1.8.1)

include_directories(lib/googletest/include lib/googletest)
add_subdirectory(lib/googletest)

add_executable(Sem2_contest3_2a main.cpp IWeighedGraph.h Edge.cpp Edge.h ListWeighedGraph.cpp ListWeighedGraph.h GraphAlgorithms.cpp GraphAlgorithms.h MertixCompleteGraphGenerator.cpp MertixCompleteGraphGenerator.h)
target_link_libraries(Sem2_contest3_2a gtest gtest_main)