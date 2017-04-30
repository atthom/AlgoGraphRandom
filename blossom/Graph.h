//
// Created by RobLocal on 4/29/2017.
//

#ifndef ALGOGRAPHRANDOM_GRAPH_H
#define ALGOGRAPHRANDOM_GRAPH_H

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <set>
using std::set;

namespace Blossom {

    typedef unsigned int node;

    class Graph {
    public:
        map<node, set<node>> adjs;
        node n = 0;
        unsigned int nEdges = 0;

        Graph(unsigned int n, double probability);

        Graph(const Graph &graph);

        Graph();

        void connect(node a, node b);

        void disconnect(node a, node b);

        void addNode(node nd);

        bool nodeExist(node nd) const;

        bool edgeExist(node a, node b) const;
    };

}


#endif //ALGOGRAPHRANDOM_GRAPH_H
