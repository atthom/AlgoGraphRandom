/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategies.cpp
 * Author: chronos
 * 
 * Created on March 23, 2017, 1:39 AM
 */

#include "Strategies.h"
#include <algorithm>
#include <list>

using namespace std;

Strategies::Strategies() {
}


Strategies::~Strategies() {
}

void Strategies::Hongrois(RandomBiGraph G) {
    
    // on place des edges randoms jusqu'a ce qu'on puisse plus
    vector<Edge> edges_matched;
    vector<Node> nodes_matched;
    
    vector<Edge> edges = G.edges;  
    
    for(int it = 0 ; it < G.nb_sommet1; ++it)   { 
        Node current_node = G.left[it];
        //nodes_matched.    
        if(find(nodes_matched.begin(), nodes_matched.end(), current_node) != nodes_matched.end()) {
            continue;
        } else {
            vector<Node> neighbor = current_node.getSucc();
            for(vector<Node>::iterator j = neighbor.begin() ; j != neighbor.end(); ++j)   { 
               if(find(nodes_matched.begin(), nodes_matched.end(), current_node) == neighbor.end()) {
                   nodes_matched.push_back(*j);
                   nodes_matched.push_back(G.left[it]);
                   edges_matched.push_back({G.left[it], *j});
                   break;
               }
            }
        }
    }
    
}


void Strategies::BFS(Node* U, int nb_sommet, int current_sommet, bool *visited) {
    // Mark all the vertices as not visited
    
    for(int i = 0; i < nb_sommet; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[current_sommet] = true;
    queue.push_back(current_sommet);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())    {
        
        // Dequeue a vertex from queue and print it
        current_sommet = queue.front();
        queue.pop_front(); 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        vector<Node> vector_next = U[current_sommet].getSucc();
        
        for(vector<Node>::iterator it = vector_next.begin() ; it != vector_next.end(); ++it)   { 
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    
}
/*
void Strategies::DFSUtil(Node* U, int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    vector<Node> vector_next = U[v].getSucc();
    
    for(vector<Node>::iterator it = vector_next.begin() ; it != vector_next.end(); ++it)   { 
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
                
    }
        
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Strategies::DFS(int v, bool *visited)
{
    // Mark all the vertices as not visited
    for (int i = 0; i < v; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

void Strategies::Hopcroft(RandomBiGraph G) {
    bool *Pair_U = new bool[G.nb_sommet1];
    bool *Pair_V = new bool[G.nb_sommet2];
    
    for (int i=0; i< G.nb_sommet1; i++) {
        Pair_U[i] = false;        
    } 
    
    for (int i=0; i< G.nb_sommet2; i++) {
        Pair_V[i] = false;        
    } 
    int matching = 0;
    while (BFS(G.left, G.nb_sommet1, 0, Pair_U)) {
        for(int i=0; i< G.nb_sommet1; i++) {
            if(Pair_U[G.left[i].id]== false ) {
                if(DFS(i, Pair_V)== true) {
                    matching++;
                }
            }
        }
    }
}
*/