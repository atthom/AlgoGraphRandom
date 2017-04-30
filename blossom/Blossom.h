//
// Created by RobLocal on 4/29/2017.
//

#ifndef ALGOGRAPHRANDOM_BLOSSOM_H
#define ALGOGRAPHRANDOM_BLOSSOM_H

#include <set>
using std::set;

#include "Graph.h"

namespace Blossom {

    class Blossom {
    public:
        Blossom(node root, vector<node> &cycle, set<node> nodes);

        Blossom(const Blossom &blossom);

    public:
        node root;
        vector<node> cycle;
        set<node> nodes;
    };

}

#endif //ALGOGRAPHRANDOM_BLOSSOM_H
