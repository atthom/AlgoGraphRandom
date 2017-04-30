//
// Created by RobLocal on 4/29/2017.
//

#include <queue>
#include <iostream>

using std::queue;

#include "BlossomAlgo.h"

namespace Blossom {

    BlossomAlgo::BlossomAlgo(const Graph &graph) :
            graph(graph), nil(graph.n) {}

    unsigned int BlossomAlgo::matching() {
        Graph result;
        //result.adj = vector<vector<node>>(result.n);
        for (const std::pair<const node, set<node>> &nd: graph.adjs) {
            result.addNode(nd.first);
        }
        while (true) {
            std::cout << "edges: " << result.nEdges << std::endl;
            vector<node> path = findAlternatingPath(graph, result);
            if (path.empty())
                return result.nEdges;
            updateMatching(path, result);
        }
    }

    vector<node> BlossomAlgo::findAlternatingPath(const Graph &g, const Graph &m) {
        vector<NodeInfo> forest(graph.n);
        queue<Edge> worklist;
        for (const std::pair<const node, set<node>> &nds : g.adjs) {
            node nd = nds.first;
            if (!m.adjs.at(nd).empty()) continue;
            forest.at(nd) = NodeInfo(nil, nd, true);
            for (node endpoint : g.adjs.at(nd)) {
                worklist.emplace(nd, endpoint);
            }
        }
        while (!worklist.empty()) {
            Edge curr = worklist.front();
            worklist.pop();
            if (m.edgeExist(curr.start, curr.end)) continue;
            NodeInfo startInfo = forest.at(curr.start);
            NodeInfo endInfo = forest.at(curr.end);
            if (!endInfo.null) {
                if (endInfo.isOuter && startInfo.treeRoot == endInfo.treeRoot) {
                    Blossom blossom = findBlossom(forest, curr);
                    vector<node> path = findAlternatingPath(contractGraph(g, blossom), contractGraph(m, blossom));
                    if (path.empty())
                        return path;
                    return expandPath(path, g, blossom);
                } else if (endInfo.isOuter && startInfo.treeRoot != endInfo.treeRoot) {
                    vector<node> result;
                    for (node nd = curr.start; nd != nil; nd = forest.at(nd).parent) {
                        result.push_back(nd);
                    }
                    result = reversePath(result);
                    for (node nd = curr.end; nd != nil; nd = forest.at(nd).parent) {
                        result.push_back(nd);
                    }
                    return result;
                }
            } else {
                forest.at(curr.end) = NodeInfo(curr.start, startInfo.treeRoot, false);
                node endpoint = *m.adjs.at(curr.end).begin();
                forest.at(endpoint) = NodeInfo(curr.end, startInfo.treeRoot, true);
                for (node fringeNode : g.adjs.at(endpoint)) {
                    worklist.emplace(endpoint, fringeNode);
                }
            }
        }
        return vector<node>(0);
    }

    Blossom BlossomAlgo::findBlossom(const vector<NodeInfo> &forest, const Edge &edge) {
        vector<node> onePath;
        vector<node> twoPath;
        for (node nd = edge.start; nd != nil; nd = forest.at(nd).parent) {
            onePath.emplace(onePath.begin(), nd);
        }
        for (node nd = edge.end; nd != nil; nd = forest.at(nd).parent) {
            twoPath.emplace(twoPath.begin(), nd);
        }
        int mismatch = 0;
        for (; mismatch < onePath.size() && mismatch < twoPath.size(); ++mismatch) {
            if (onePath.at(mismatch) != twoPath.at(mismatch)) break;
        }
        vector<node> cycle;
        for (int i = mismatch - 1; i < onePath.size(); ++i) {
            cycle.push_back((node) onePath.at(i));
        }
        for (int i = twoPath.size() - 1; i >= mismatch - 1; --i) {
            cycle.push_back((node) twoPath.at(i));
        }
        return Blossom(onePath.at(mismatch - 1), cycle, set<node>(cycle.begin(), cycle.end()));
    }

    Graph BlossomAlgo::contractGraph(const Graph &g, const Blossom &blossom) {
        Graph result;
        for (const std::pair<const node, set<node>> &nds : g.adjs) {
            node nd = nds.first;
            if (blossom.nodes.count(nd) == 0) {
                result.addNode(nd);
            }
        }
        result.addNode(blossom.root);
        for (const std::pair<const node, set<node>> &nds : g.adjs) {
            node nd = nds.first;
            if (blossom.nodes.count(nd) != 0) continue;
            for (node endpoint:g.adjs.at(nd)) {
                if (blossom.nodes.count(endpoint) != 0) {
                    endpoint = blossom.root;
                }
                result.connect(nd, endpoint);
            }
        }
        return result;
    }

    vector<node> BlossomAlgo::expandPath(vector<node> path, const Graph &graph, const Blossom &blossom) {
        int index = -1;
        for (int i = 0; i < path.size(); ++i) {
            if (path.at(i) == blossom.root) {
                index = i;
                break;
            }
        }
        if (index == -1) return path;
        if (index % 2 == 1) {
            path = reversePath(path);
        }
        vector<node> result;
        for (int i = 0; i < path.size(); ++i) {
            if (path.at(i) != blossom.root) {
                result.push_back((node) path.at(i));
            } else {
                result.push_back(blossom.root);
                node outNode = findNodeLeavingCycle(graph, blossom, path.at(i + 1));
                int outIndex = -1;
                for (int j = 0; j < blossom.cycle.size(); ++j) {
                    if (blossom.cycle.at(j) == outNode) {
                        outIndex = j;
                        break;
                    }
                }
                int start = (outIndex % 2 == 0) ? 1 : blossom.cycle.size() - 2;
                int step = (start < outIndex) ? 1 : -1;
                for (int k = start; k != outIndex; k += step) {
                    result.push_back((node) blossom.cycle.at(k));
                }
                result.push_back(outNode);
            }
        }
        return result;
    }

    vector<node> BlossomAlgo::reversePath(const vector<node> &path) {
        vector<node> result;
        for (int i = path.size() - 1; i >= 0; --i) {
            result.push_back((node) path.at(i));
        }
        return result;
    }

    node BlossomAlgo::findNodeLeavingCycle(const Graph &graph, Blossom blossom, node nd) {
        for (node cycleNode : blossom.nodes) {
            if (graph.edgeExist(cycleNode, nd)) {
                return cycleNode;
            }
        }
    }

    void BlossomAlgo::updateMatching(vector<node> path, Graph &graph) {
        for (int i = 0; i < path.size() - 1; ++i) {
            if (graph.edgeExist(path.at(i), path.at(i + 1))) {
                graph.disconnect(path.at(i), path.at(i + 1));
            } else {
                graph.connect(path.at(i), path.at(i + 1));
            }
        }
    }

}