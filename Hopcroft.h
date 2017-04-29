
#ifndef HOPCROFT_H
#define HOPCROFT_H

#include "RandomBiGraph.h"
#include "BipartGraph.h"

class Hopcroft {
private:
    const BipartGraph& graph;
    const node_u nil;
    vector<node_v> Pair_U;
    vector<node_u> Pair_V;
    vector<unsigned int> Dist;

    bool BFS();
    bool DFS(node_u u);
public:
    Hopcroft(const BipartGraph& graph);

    unsigned int matching();

};

#endif /* HOPCROFT_H */

