cmake_minimum_required(VERSION 3.6)
project(AlgoGraphRandom)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Edge.cpp
        Edge.h
        Main.cpp
        Node.cpp
        Node.h
        RandomBiGraph.cpp
        RandomBiGraph.h
        RandomGraph.cpp
        RandomGraph.h)

add_executable(AlgoGraphRandom ${SOURCE_FILES})