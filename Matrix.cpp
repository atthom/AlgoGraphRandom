//
// Created by RobLocal on 4/26/2017.
//

#include "Matrix.h"


Matrix::Matrix(unsigned int nx, unsigned int ny, int value) :
        matrix(nx, vector<int>(ny,value)), nx(nx), ny(ny) {}

Matrix::Matrix(const Matrix &matrix) :
        matrix(matrix.matrix), nx(matrix.nx), ny(matrix.ny){}

void Matrix::set(unsigned int x, unsigned int y, int value) {
    matrix.at(x).at(y) = value;
}

int Matrix::get(unsigned int x, unsigned int y) {
    return matrix.at(x).at(y);
}

vector<int> Matrix::selectColumn(unsigned int x) {
    return matrix.at(x);
}

vector<int> Matrix::selectRow(unsigned int y) {
    vector<int> v(nx);
    for (unsigned int x = 0; x < nx; x++){
        v.at(x) = matrix.at(x).at(y);
    }
    return v;
}


ostream& operator<<(ostream& os, Matrix& M)  {
    os << "\n(" << M.nx << ", " << M.ny << ")\n";

    for (unsigned int i=0; i< M.nx; i++) {

        vector<int> row = M.selectRow(i);
        os << "{ ";
        for (auto j: row)
            os << j << ", ";
        os << "}\n";
    }

    return os;
}

