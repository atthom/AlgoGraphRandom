/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategies.h
 * Author: chronos
 *
 * Created on March 23, 2017, 1:39 AM
 */

#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "Node.h"
#include "RandomBiGraph.h"

class Strategies {

public:
    Strategies();
    virtual ~Strategies();
    void BFS(Node* U, int nb_sommet, int current_sommet, bool *visited);
    void DFSUtil(Node* U, int v, bool visited[]);
    void DFS(int v, bool *visited);
    void Hongrois(RandomBiGraph G);
    void Hopcroft(RandomBiGraph G);
private:

};

#endif /* STRATEGIES_H */

