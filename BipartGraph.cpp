//
// Created by RobLocal on 4/28/2017.
//

#include "BipartGraph.h"

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include <iostream>

BipartGraph::BipartGraph(unsigned int nu, unsigned int nv, double probability):
    nu(nu),nv(nv),adjU(nu),adjV(nv){
    probability *= RAND_MAX;

    //std::cout << "p: " << probability << std::endl;
    //std::cout << "MAX: " << RAND_MAX << std::endl;
    srand(time(0));
    for (node_u u = 0; u < nu; ++u) {
        for (node_v v = 0; v < nv; ++v) {
            unsigned int r = rand();
            //std::cout << "r: " << r << std::endl;
            if(r <= probability){
                //std::cout << "r higher " << std::endl;
                connect(u,v);
            }
        }
    }
}

void BipartGraph::connect(node_u u, node_v v) {
    adjU.at(u).push_back(v);
    adjV.at(v).push_back(u);
}
