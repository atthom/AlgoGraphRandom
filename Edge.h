/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.h
 * Author: chronos
 *
 * Created on March 20, 2017, 8:45 PM
 */

#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Edge {
public:
    Edge(Node n1,Node n2);

    virtual ~Edge();
private:
    Node n1;
    Node n2;

};

#endif /* EDGE_H */

