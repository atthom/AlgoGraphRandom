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

RandomBiGraph::RandomBiGraph(int nb1, int nb2, float p):
    nb_sommet1(nb1), nb_sommet2(nb2), p(p) {
    
    left = new Node[nb1];
    right = new Node[nb2];
    
    srand(time(0));
    int threshold = p*100;
    
    for (int i = 0; i < nb1; i++) {
        for (int j = 0; j < nb2; j++) {
            int random_val = std::rand() % 100;

            left[i].id = i;
            right[j].id = j;

            if(random_val < threshold) {
                left[i].addSucc(right[j]);
                edges.push_back(Edge(left[i], right[j]));
            } 
        }
    }

}

vector<Edge> RandomBiGraph::get_edges() {
    return edges;
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

