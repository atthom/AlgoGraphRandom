//
// Created by RobLocal on 4/29/2017.
//

#ifndef ALGOGRAPHRANDOM_NODEINFO_H
#define ALGOGRAPHRANDOM_NODEINFO_H


#include "Graph.h"

namespace Blossom {

    class NodeInfo {
    public:
        NodeInfo(node parent, node treeRoot, bool isOuter);

        NodeInfo(const NodeInfo &nodeInfo);

        NodeInfo();

        bool null;
        node parent;
        node treeRoot;
        bool isOuter;
    };

}

#endif //ALGOGRAPHRANDOM_NODEINFO_H
