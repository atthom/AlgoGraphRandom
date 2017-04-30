//
// Created by RobLocal on 4/28/2017.
//

#include "BipartGraph.h"

#include <cstdlib>
using std::rand;

BipartGraph::BipartGraph(unsigned int nu, unsigned int nv, double probability):
    nu(nu),nv(nv),adjU(nu),adjV(nv)
{
    probability *= RAND_MAX;
    for (node_u u = 0; u < nu; ++u) {
        for (node_v v = 0; v < nv; ++v) {
            unsigned int r = rand();
            if(r <= probability){
                connect(u,v);
            }
        }
    }
}

void BipartGraph::connect(node_u u, node_v v) {
    adjU.at(u).push_back(v);
    adjV.at(v).push_back(u);
}
