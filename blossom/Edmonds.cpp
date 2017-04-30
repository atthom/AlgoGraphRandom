//
// Created by RobLocal on 4/30/2017.
//

#include <iostream>
#include "Edmonds.h"

namespace Edmonds{

    int lca(vector<int>& match, vector<int>& base, vector<int>& p, int a, int b){
        vector<bool> used(match.size(), false);
        while(true){
            a = base.at(a);
            used.at(a) = true;
            if(match.at(a) == -1) break;
            a = p.at(match.at(a));
        }
        while (true){
            b = base.at(b);
            if(used.at(b)) return b;
            b = p.at(match.at(b));
        }
    }

    void markPath(vector<int>& match, vector<int>& base, vector<bool>& blossom, vector<int>& p, int v, int b, int children){
        //std::cout << "start" << std::endl;
        for (; base.at(v) != b; v = p.at(match.at(v))) {
            blossom.at(base.at(match.at(v))) = true;
            blossom.at(base.at(v)) = true;
            p.at(v) = children;
            children = match.at(v);
        }
        //std::cout << "end" << std::endl;
    }

    int findPath(const Graph& graph, vector<int>& match, vector<int>& p, int root ){
        vector<bool> used(graph.n, false);
        p = vector<int>(graph.n,-1);
        vector<int> base(graph.n, 0);
        for (int i = 0; i < graph.n; ++i) {
            base.at(i) = i;
        }
        used.at(root) = true;
        int qh = 0;
        int qt = 0;
        vector<int> q(graph.n, 0);
        q.at(qt++) = root;
        while (qh < qt){
            int v = q.at(qh++);
            for(int to : graph.adjs.at(v)){
                if(base.at(v) == base.at(to) || match.at(v) == to) continue;
                if(to == root || match.at(to) != -1 && p.at(match.at(to)) != -1){
                    int curbase = lca(match, base, p, v, to);
                    vector<bool> blossom(graph.n, false);
                    markPath(match, base, blossom, p, v, curbase, to);
                    markPath(match, base, blossom, p, to, curbase, v);
                    for (int i = 0; i < graph.n; ++i) {
                        if(blossom.at(base.at(i))){
                            base.at(i) = curbase;
                            if(!used.at(i)){
                                used.at(i) = true;
                                q.at(qt++) = i;
                            }
                        }
                    }
                }
                else if(p.at(to) == -1){
                    p.at(to) = v;
                    if(match.at(to) == -1) return to;
                    to = match.at(to);
                    used.at(to) = true;
                    q.at(qt++) = to;
                }
            }
        }
        return -1;
    }

    unsigned int matching(const Graph& graph){
        vector<int> match(graph.n,-1);
        vector<int> p(graph.n, 0);
        for (int i = 0; i < graph.n; ++i) {
            if(match.at(i) == -1){
                int v = findPath(graph,match,p,i);
                while(v != -1){
                    int pv = p.at(v);
                    int ppv = match.at(pv);
                    match.at(v) = pv;
                    match.at(pv) = v;
                    v = ppv;
                }
            }
        }
        unsigned int matches = 0;
        for (int j = 0; j < graph.n; ++j) {
            if(match.at(j) != -1){
                ++matches;
            }
        }
        return matches/2;
    }


}