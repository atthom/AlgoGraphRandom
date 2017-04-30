/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomBiGraph.cpp
 * Author: chronos
 * 
 * Created on March 20, 2017, 6:28 PM
 */

#include "RandomBiGraph.h"
#include <random>

using namespace std;

RandomBiGraph::RandomBiGraph(unsigned int nb1,unsigned int nb2, float p):
    nb_sommet1(nb1), nb_sommet2(nb2), p(p) {
    
    left = new Node[nb1];
    right = new Node[nb2];

    int threshold = (int)p*100;
    
    for (unsigned int i = 0; i < nb1; i++) {
        for (unsigned int j = 0; j < nb2; j++) {
            left[i].id = i;
            right[j].id = j;

            int random_val = std::rand() % 100;
            if(random_val < threshold) {
                left[i].addSucc(right[j]);
                edges.push_back(Edge(left[i], right[j]));
            } 
        }
    }

}

Node* RandomBiGraph::get_left() {
    return left;
}

Node* RandomBiGraph::get_right() {
    return right;
}

bool RandomBiGraph::isMaximum() {
    
}

bool RandomBiGraph::isMaximal() {
        
}

bool isPerfect() {
    
}   

ostream& operator<<(ostream& os, const RandomBiGraph& graph)  {
    os << "left{";
    for (int i=0; i< graph.nb_sommet1;i++) {
        os << graph.left << ",";
    }
    os << "}\n";
    
    os << "right{";
    for (int i=0; i< graph.nb_sommet2;i++) {
        os << graph.right << ",";
    }
    os << "}\n";
    os << "Edges{";
    for(vector<Edge>::const_iterator j = graph.edges.begin() ; j != graph.edges.end(); ++j)   { 
        os << *j;
    }
    os << "}\n";
    
    return os;
}

RandomBiGraph::~RandomBiGraph() {
   // delete left;
   // delete right;
}

