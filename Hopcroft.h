/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hopcroft.h
 * Author: chronos
 *
 * Created on March 23, 2017, 1:39 AM
 */

#ifndef HOPCROFT_H
#define HOPCROFT_H

#include "Node.h"
#include "RandomBiGraph.h"
#include "BipartGraph.h"

class Hopcroft {
private:
    const BipartGraph& graph;
    const node_u nil;
    vector<node_v> Pair_U;
    vector<node_u> Pair_V;
    vector<unsigned int> Dist;
public:
    Hopcroft(const BipartGraph& graph);

    bool BFS();
    bool DFS(node_u u);
    unsigned int compute();

};

#endif /* STRATEGIES_H */

