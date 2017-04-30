//
// Created by RobLocal on 4/29/2017.
//

#ifndef ALGOGRAPHRANDOM_BLOSSOMALGO_H
#define ALGOGRAPHRANDOM_BLOSSOMALGO_H

#include "Graph.h"
#include "Blossom.h"
#include "Edge.h"
#include "NodeInfo.h"

namespace Blossom {

    class BlossomAlgo {
    private:
        const Graph &graph;
        const node nil;

    public:
        explicit BlossomAlgo(const Graph &graph);

        unsigned int matching();

        vector<node> findAlternatingPath(const Graph &g, const Graph &m);

        Blossom findBlossom(const vector<NodeInfo> &forest, const Edge &edge);

        Graph contractGraph(const Graph &graph, const Blossom &blossom);

        vector<node> expandPath(vector<node> path, const Graph &graph, const Blossom &blossom);

        vector<node> reversePath(const vector<node> &path);

        node findNodeLeavingCycle(const Graph &graph, Blossom blossom, node nd);

        void updateMatching(vector<node> path, Graph &graph);
    };

}

#endif //ALGOGRAPHRANDOM_BLOSSOM_H
