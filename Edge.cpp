/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.cpp
 * Author: chronos
 * 
 * Created on March 20, 2017, 8:45 PM
 */

#include "Edge.h"

Edge::Edge(Node n1, Node n2) : n1(n1), n2(n2) {
}

ostream& operator<<(ostream& os, const Edge& e) {
    os << "("<< e.n1 << "," << e.n2 << ")";
    return os;
}

Edge::~Edge() {
}

int Edge::getIDn1() {
    return n1.id;
}

int Edge::getIDn2() {
    return n2.id;
}
