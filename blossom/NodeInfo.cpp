//
// Created by RobLocal on 4/29/2017.
//

#include "NodeInfo.h"

namespace Blossom {

    NodeInfo::NodeInfo(node parent, node treeRoot, bool isOuter) :
            null(false),
            parent(parent),
            treeRoot(treeRoot),
            isOuter(isOuter) {}

    NodeInfo::NodeInfo() :
            null(true) {}

    NodeInfo::NodeInfo(const NodeInfo &nodeInfo) :
            null(nodeInfo.null),
            parent(nodeInfo.parent),
            treeRoot(nodeInfo.treeRoot),
            isOuter(nodeInfo.isOuter) {}
}