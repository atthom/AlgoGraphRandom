cmake_minimum_required(VERSION 3.6)
project(AlgoGraphRandom)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-O3")

set(SOURCE_FILES
        Edge.cpp
        Edge.h
        Main.cpp
        Node.cpp
        Node.h
        RandomBiGraph.cpp
        RandomBiGraph.h
        RandomGraph.cpp
        RandomGraph.h
        Hopcroft.cpp
        Hopcroft.h
        Matrix.cpp
        Matrix.h
        BipartGraph.cpp
        BipartGraph.h
        Hongrois.cpp
        Hongrois.h
        blossom/Graph.cpp
        blossom/Graph.h
        blossom/BlossomAlgo.cpp
        blossom/BlossomAlgo.h
        blossom/NodeInfo.cpp
        blossom/NodeInfo.h
        blossom/Edge.cpp
        blossom/Edge.h
        blossom/Blossom.cpp
        blossom/Blossom.h)

add_executable(AlgoGraphRandom ${SOURCE_FILES})