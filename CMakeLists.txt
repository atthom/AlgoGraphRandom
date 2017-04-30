cmake_minimum_required(VERSION 3.6)
project(AlgoGraphRandom)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O3")

set(SOURCE_FILES
        Main.cpp
        hopcroft/Hopcroft.cpp
        hopcroft/Hopcroft.h
        hopcroft/BipartGraph.cpp
        hopcroft/BipartGraph.h
        blossom/Edmonds.cpp
        blossom/Edmonds.h
        blossom/Graph.cpp
        blossom/Graph.h)

add_executable(AlgoGraphRandom ${SOURCE_FILES})