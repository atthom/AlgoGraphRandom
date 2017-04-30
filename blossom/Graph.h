//
// Created by RobLocal on 4/30/2017.
//

#ifndef ALGOGRAPHRANDOM_GRAPH_H
#define ALGOGRAPHRANDOM_GRAPH_H

#include <vector>
using std::vector;

typedef unsigned int node;

class Graph {
public:
    Graph(unsigned int n, double p);
    node n;
    vector<vector<node>> adjs;

};


#endif //ALGOGRAPHRANDOM_GRAPH_H
