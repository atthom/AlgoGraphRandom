
#include <cstdlib>
using std::srand;

#include "RandomBiGraph.h"
#include "BipartGraph.h"
#include "Hopcroft.h"
#include "Matrix.h"
#include "Hongrois.h"

void hopcroft(unsigned int n, unsigned int ntests){
    std::cout << "Hopcrof-Karp" << std::endl;
    for (double p = 0.005; p < 0.035; p+=0.001) {
        std::cout << "p: " << p << std::endl;
        unsigned int perfectGraphs = 0;
        for (int i = 0; i < ntests; ++i) {
            BipartGraph graph(n, n, p);
            Hopcroft h(graph);
            unsigned int matching = h.matching();
            if(matching == n){
                perfectGraphs++;
            }
        }
        std::cout << "perfect: " << perfectGraphs << "/" << ntests << std::endl;
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
    srand(time(0));
    hopcroft(500,1000);
    //hongrois();
}
