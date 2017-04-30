//
// Created by RobLocal on 4/29/2017.
//

#include "Graph.h"

#include <cstdlib>
#include <iostream>

using std::rand;

namespace Blossom {

    Graph::Graph(const Graph &graph) :
            n(graph.n), adjs(graph.adjs) {}

    Graph::Graph(unsigned int n, double probability) :
            n(0), adjs() {
        for (node a = 0; a < n; ++a) {
            addNode(a);
        }
        probability *= RAND_MAX;
        for (node a = 0; a < n; ++a) {
            for (node b = a + 1; b < n; ++b) {
                unsigned int r = rand();
                if (r <= probability) {
                    connect(a, b);
                }
            }
        }
    }

    void Graph::connect(node a, node b) {
        if (nodeExist(a) && nodeExist(b)) {
            adjs.at(a).insert(b);
            adjs.at(b).insert(a);
            ++nEdges;
        } else {
            std::cout << "Connect error" << std::endl;
            abort();
        }

    }

    void Graph::addNode(node nd) {
        adjs.emplace(nd, set<node>());
        ++n;
    }

    bool Graph::edgeExist(const node a, const node b) const {
        if (nodeExist(a)) {
            return adjs.at(a).count(b) != 0;
        }
        return false;
    }

    void Graph::disconnect(node a, node b) {
        if (nodeExist(a) && nodeExist(b)) {
            adjs.at(a).erase(b);
            adjs.at(b).erase(a);
            --nEdges;
        } else {
            std::cout << "Disconnect error" << std::endl;
            abort();
        }
    }

    Graph::Graph() {}

    bool Graph::nodeExist(node nd) const {
        auto it = adjs.find(nd);
        return it != adjs.end();
    }

}