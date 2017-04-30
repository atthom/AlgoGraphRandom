//
// Created by RobLocal on 4/29/2017.
//

#ifndef ALGOGRAPHRANDOM_EDGE2_H
#define ALGOGRAPHRANDOM_EDGE2_H


#include "Graph.h"

namespace Blossom {

    class Edge {
    public:
        Edge(node start, node end);

        const node start;
        const node end;
    };

}

#endif //ALGOGRAPHRANDOM_EDGE2_H
