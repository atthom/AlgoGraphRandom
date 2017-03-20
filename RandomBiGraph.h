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

class RandomBiGraph {
public:
    RandomBiGraph(int nb, int nb2, float p);
    
    virtual ~RandomBiGraph();
private:
    int nb_sommet1;
    int nb_sommet2;
    float p;
    

};

#endif /* RANDOMBIGRAPH_H */

