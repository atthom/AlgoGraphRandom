

#include "RandomBiGraph.h"
#include "BipartGraph.h"
#include "Hopcroft.h"
#include "Matrix.h"
#include "Hongrois.h"

void hopcroft(){
    std::cout << "Hopcrof-Karp" << std::endl;
    for (double p = 0; p < 0.01; p+=0.0001) {
        std::cout << "p: " << p << std::endl;
        BipartGraph graph(500, 500, p);
        Hopcroft h(graph);
        unsigned int matching = h.compute();
        std::cout << "Matching: " << matching << std::endl;
    }
    std::cout << "Done" << std::endl;
}

void hongrois(){
    std::cout << "Hongrois" << std::endl;
    cout << "Generate Bipartit" << endl;
    RandomBiGraph graph(20, 20, 0.1);
    cout << "Done" << endl;

    cout << "Implement Algo Hongrois..." << endl;
    Hongrois h(graph);
    cout << "Done" << endl;
}

int main (int argc, char *argv[]) {
    hopcroft();
    hongrois();
}
