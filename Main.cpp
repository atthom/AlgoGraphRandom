

#include "RandomBiGraph.h"
#include "BipartGraph.h"
#include "Hopcroft.h"

int main (int argc, char *argv[]) {
    for (double p = 0; p < 0.01; p+=0.0001) {
        std::cout << "p: " << p << std::endl;
        BipartGraph graph(500, 500, p);
        Hopcroft h(graph);
        unsigned int matching = h.compute();
        std::cout << "Matching: " << matching << std::endl;
    }
    std::cout << "Done" << std::endl;
}
