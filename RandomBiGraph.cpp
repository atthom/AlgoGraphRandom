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
#include "Edge.h"
#include <time.h>
#include <random>
#include <iostream>

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
            if(random_val < threshold) {
                cout << random_val << endl;    
                
                left[i].addSucc(right[j]);
                
                edges.push_back(Edge(left[i], right[j]));
         
            } 
        }
    }

}


bool RandomBiGraph::isMaximum() {
    
}

bool RandomBiGraph::isMaximal() {
        
}

bool isPerfect() {
    
}   

RandomBiGraph::~RandomBiGraph() {
   // delete left;
   // delete right;
}

