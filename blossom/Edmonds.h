//
// Created by RobLocal on 4/30/2017.
//

#ifndef ALGOGRAPHRANDOM_EDMONDS_H
#define ALGOGRAPHRANDOM_EDMONDS_H


#include "Graph.h"

namespace Edmonds{

    int lca(vector<int>& match, vector<int>& base, vector<int>& p, int a, int b);

    void markPath(vector<int>& match, vector<int>& base, vector<bool>& blossom, vector<int>& p, int v, int b, int children);

    int findPath(const Graph& graph, vector<int>& match, vector<int>& p, int root );

    unsigned int matching(const Graph& graph);

}

#endif //ALGOGRAPHRANDOM_EDMONDS_H
