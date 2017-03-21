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

}


RandomBiGraph::~RandomBiGraph() {
	delete left;
	delete right;
}

