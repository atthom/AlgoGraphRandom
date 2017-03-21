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

RandomBiGraph::RandomBiGraph(int nb1, int nb2, float p):
	nb_sommet1(nb1), nb_sommet2(nb2), p(p){
	left = new Node[nb1];
	right = new Node[nb2];

RandomBiGraph(int nb, int nb2, float p) {
    std::srand(std::time(0));
    int percent = p*100;
    
    for (int i = 0; i < nb; i++) {
        for (int i = 0; i < nb2; i++) {
            int random_val = std::rand() % percent;
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
	delete left;
	delete right;
}

