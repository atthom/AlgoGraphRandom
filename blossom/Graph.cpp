//
// Created by RobLocal on 4/30/2017.
//

#include <cstdlib>
#include "Graph.h"

using std::rand;

Graph::Graph(unsigned int n, double p):
    n(n),adjs(n){
    p *= RAND_MAX;
    for (node a = 0; a < n; ++a) {
        for (node b = a + 1; b < n; ++b) {
            unsigned int r = rand();
            if (r <= p) {
                adjs.at(a).push_back(b);
                adjs.at(b).push_back(a);
            }
        }
    }
}
