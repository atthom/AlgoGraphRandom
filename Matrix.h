//
// Created by RobLocal on 4/26/2017.
//

#ifndef ALGOGRAPHRANDOM_MATRIX_H
#define ALGOGRAPHRANDOM_MATRIX_H

#include <vector>
using std::vector;

class Matrix {
private:
    unsigned int nx;
    unsigned int ny;
    vector<vector<int>> matrix;
public:
    Matrix(const Matrix& matrix);
    Matrix(unsigned int nx, unsigned int ny, int value = 0);
    void set(unsigned int x, unsigned int y, int value);
    int get(unsigned int x, unsigned int y);
    vector<int> selectRow(unsigned int y);
    vector<int> selectColumn(unsigned int x);
};


#endif //ALGOGRAPHRANDOM_MATRIX_H
