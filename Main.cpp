

#include "RandomBiGraph.h"
#include "Matrix.h"
#include "Hongrois.h"

int main (int argc, char *argv[]) {

    cout << "Generate Bipartit" << endl;
    RandomBiGraph graph(20, 20, 0.1);
    cout << "Done" << endl;

    cout << "Implement Algo Hongrois..." << endl;
    Hongrois h(graph);


    cout << "Done" << endl;
}
