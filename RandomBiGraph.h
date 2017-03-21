/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomBiGraph.h
 * Author: chronos
 *
 * Created on March 20, 2017, 6:28 PM
 */

#ifndef RANDOMBIGRAPH_H
#define RANDOMBIGRAPH_H

#include "Node.h"

class RandomBiGraph {
public:
    RandomBiGraph(int nb1, int nb2, float p);

    virtual ~RandomBiGraph();
private:
    const int nb_sommet1;
    const int nb_sommet2;
    float p;
    Node* left;
    Node* right;
    

};

#endif /* RANDOMBIGRAPH_H */

