/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: chronos
 * 
 * Created on March 20, 2017, 6:27 PM
 */

#include "Node.h"

Node::Node(int id): id(id) {
    
}

Node::Node(): id(0) {
    
}

void Node::addSucc(Node foo) {
    //succ.insert(foo);
}

Node::~Node() {
}

