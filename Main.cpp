

#include "RandomBiGraph.h"
#include "Matrix.h"

int main (int argc, char *argv[]) {
  //  RandomBiGraph graph(500, 500, 0.5);

    Matrix mat = Matrix(5, 5, 0);
    cout << "Begin..." << endl;

    for(unsigned int i = 0; i < mat.nx; ++i) {
        for(unsigned int j = 0; j < mat.ny; ++j) {
            mat.set(i, j, i*j + 1);
        }
    }


    cout << mat << endl;

    cout << "\nDone" << endl;
}
