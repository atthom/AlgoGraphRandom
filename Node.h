/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: chronos
 *
 * Created on March 20, 2017, 6:27 PM
 */

#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;

class Node {
public:
    Node(int id);
    Node();
    void addSucc(Node n);
    vector<Node> getSucc();
    int id;
    
    virtual ~Node();
private:
    
    // successors
    vector<Node> succ;
    
};

#endif /* NODE_H */

