//
// Created by RobLocal on 4/28/2017.
//

#ifndef ALGOGRAPHRANDOM_BIPARTGRAPH_H
#define ALGOGRAPHRANDOM_BIPARTGRAPH_H

#include <vector>
using std::vector;

typedef unsigned int node_u;
typedef unsigned int node_v;

class BipartGraph {
private:
    void connect(unsigned int u, unsigned int v);
public:
    BipartGraph(unsigned int nu, unsigned int nv, double probability);
    const node_u nu;
    const node_v nv;
    vector<vector<node_u>> adjU;
    vector<vector<node_v>> adjV;
};


#endif //ALGOGRAPHRANDOM_BIPARTGRAPH_H
