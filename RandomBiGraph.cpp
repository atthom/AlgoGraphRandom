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
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "RandomBiGraph.h"

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
}

