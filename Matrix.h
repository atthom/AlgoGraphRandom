//
// Created by RobLocal on 4/26/2017.
//

#ifndef ALGOGRAPHRANDOM_MATRIX_H
#define ALGOGRAPHRANDOM_MATRIX_H

#include <vector>
#include <iostream>
using std::vector;
using std::ostream;

class Matrix {
private:

    vector<vector<int>> matrix;
    friend ostream& operator<<(ostream& os, Matrix& M) ;
public:
    Matrix(const Matrix& matrix);
    Matrix(unsigned int nx, unsigned int ny, int value = 0);
    void set(unsigned int x, unsigned int y, int value);
    int get(unsigned int x, unsigned int y);
    vector<int> selectRow(unsigned int y);
    vector<int> selectColumn(unsigned int x);

    unsigned int nx;
    unsigned int ny;
};


#endif //ALGOGRAPHRANDOM_MATRIX_H
