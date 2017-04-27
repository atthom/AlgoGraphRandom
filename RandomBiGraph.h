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
#include "Edge.h"
using namespace std;

class RandomBiGraph {
    friend class Strategies;
    
public:
    RandomBiGraph(int nb, int nb2, float p);   
    bool isMaximum();
    bool isMaximal();
    bool isPerfect(); 
    Node* get_left();
    Node* get_right();
    vector<Edge> get_edges();

    friend ostream& operator<<(ostream& os, const RandomBiGraph& graph) ;
    virtual ~RandomBiGraph();

    const int nb_sommet1;
    const int nb_sommet2;
    
private:
    float p;
    Node* left;
    Node* right;
    vector<Edge> edges;
    

};

#endif /* RANDOMBIGRAPH_H */

