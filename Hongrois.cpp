//
// Created by Thom on 27/04/2017.
//

#include "Hongrois.h"
#include <algorithm>

Hongrois::Hongrois() {
}

Hongrois::~Hongrois() {
}


Hongrois::Hongrois(Matrix M) {

    step1(M);

}


Hongrois::Hongrois(RandomBiGraph G) {

}

void Hongrois::step1(Matrix M) {

    for(unsigned int i=0; i<M.nx; i++) {
        vector<int> row = M.selectRow(i);

        std::vector<int>::iterator smaller = std::min_element(std::begin(row), std::end(row));
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
