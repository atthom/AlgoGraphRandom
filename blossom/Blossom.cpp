//
// Created by RobLocal on 4/29/2017.
//

#include "Blossom.h"

namespace Blossom {

    Blossom::Blossom(node root, vector<node> &cycle, set<node> nodes) :
            root(root),
            cycle(cycle),
            nodes(nodes) {}

    Blossom::Blossom(const Blossom &blossom) :
            root(blossom.root),
            cycle(blossom.cycle),
            nodes(blossom.nodes) {}

}