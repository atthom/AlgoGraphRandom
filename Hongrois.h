//
// Created by Thom on 27/04/2017.
//

#ifndef ALGOGRAPHRANDOM_HONGROIS_H
#define ALGOGRAPHRANDOM_HONGROIS_H



#include "Node.h"
#include "RandomBiGraph.h"
#include "Matrix.h"

class Hongrois {

public:
    Hongrois();
    virtual ~Hongrois();
    Hongrois(RandomBiGraph G);
    Hongrois(Matrix M);


private:

    void step1(Matrix M);
    Matrix BiGraph2Matrix(RandomBiGraph G);
    Matrix step2(Matrix M);
    Matrix step3(Matrix M);

};

#endif //ALGOGRAPHRANDOM_HONGROIS_H
