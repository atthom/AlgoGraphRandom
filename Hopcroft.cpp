/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hopcroft.cpp
 * Author: chronos
 * 
 * Created on March 23, 2017, 1:39 AM
 */


#include "Hopcroft.h"


#include <queue>
using std::queue;

#include <climits>
#define INFINITY UINT_MAX

Hopcroft::Hopcroft(const BipartGraph &graph):
        graph(graph),
        nil(graph.nu),
        Pair_U(graph.nu,nil),
        Pair_V(graph.nv,nil),
        Dist(graph.nu+1){}

unsigned int Hopcroft::compute() {
    unsigned int matching = 0;
    while(BFS()){
        for (node_u u = 0; u < graph.nu; ++u) {
            if(Pair_U.at(u) == nil){
                if(DFS(u)){
                    matching++;
                }
            }
        }
    }
    return matching;
}

bool Hopcroft::DFS(node_u u) {
    if(u != nil){
        for (node_v v : graph.adjU.at(u)) {
            if(Dist.at(Pair_V.at(v)) == Dist.at(u)+1){
                if(DFS(Pair_V.at(v))){
                    Pair_V.at(v) = u;
                    Pair_U.at(u) = v;
                    return true;
                }
            }
        }
        Dist.at(u) = INFINITY;
        return false;
    }
    return true;
}

bool Hopcroft::BFS() {
    queue<node_u> Q;
    for (node_u u = 0; u < graph.nu; ++u) {
        if(Pair_U.at(u) == nil){
            Dist.at(u) = 0;
            Q.push(u);
        }
        else{
            Dist.at(u) = INFINITY;
        }
    }
    Dist.at(nil) = INFINITY;
    while (!Q.empty()){
        node_u u = Q.front();
        Q.pop();
        if(Dist.at(u) < Dist.at(nil)){
            for(node_v v : graph.adjU.at(u)){
                if(Dist.at(Pair_V.at(v)) == INFINITY){
                    Dist.at(Pair_V.at(v)) = Dist.at(u)+1;
                    Q.push((node_u)Pair_V.at(v));
                }
            }
        }
    }
    return Dist.at(nil) != INFINITY;
}
