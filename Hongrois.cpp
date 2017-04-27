//
// Created by Thom on 27/04/2017.
//

#include "Hongrois.h"
#include "Node.h"
#include <algorithm>

Hongrois::Hongrois() {
}

Hongrois::~Hongrois() {
}


Hongrois::Hongrois(Matrix M) {

    step1(M);

}


Hongrois::Hongrois(RandomBiGraph G) {

    Node* left = G.get_left();
    Node* right = G.get_right();

    Matrix mat = Matrix(G.nb_sommet1, G.nb_sommet2, 0);

    for(unsigned int i=0; i< G.nb_sommet1; i++) {
        vector<Node> succ = G.get_left()[i].getSucc();

        for(vector<Node>::iterator j = succ.begin() ; j != succ.end(); ++j)   {
            mat.set(i, j->id, 1);
        }
    }

    for(unsigned int i=0; i< G.nb_sommet2; i++) {
        vector<Node> succ = G.get_right()[i].getSucc();

        for(vector<Node>::iterator j = succ.begin() ; j != succ.end(); ++j)   {
            mat.set(j->id, i, 1);
        }
    }


}

void Hongrois::step1(Matrix M) {

    for(unsigned int i=0; i<M.nx; i++) {
        vector<int> row = M.selectRow(i);

        vector<int>::iterator smaller = min_element(begin(row), end(row));
        cout << *smaller << " \n";
        *smaller = 0;
        cout << *smaller << " \n";
    }
}

Matrix Hongrois::step2(Matrix M) {
    return Matrix(5,5,0);
}

Matrix Hongrois::step3(Matrix M) {
    return Matrix(5,5,0);
}
