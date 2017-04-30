
#include <cstdlib>
using std::srand;

#include <ctime>
#include <iostream>

#include "hopcroft/BipartGraph.h"
#include "hopcroft/Hopcroft.h"
#include "blossom/Graph.h"
#include "blossom/Edmonds.h"


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
        std::cout << "Perfect matching: " << perfectGraphs << "/" << ntests << std::endl;
    }
    std::cout << "Done" << std::endl;
}

void blossom(unsigned int n, unsigned int ntests){
    std::cout << "Blossom" << std::endl;
    for (double p = 0.0; p < 0.1; p+=0.001) {
        std::cout << "p: " << p << std::endl;
        unsigned int perfectGraphs = 0;
        for (int i = 0; i < ntests; ++i) {
            Graph graph(n, p);
            unsigned int matching = Edmonds::matching(graph);
            if(matching == n/2){
                perfectGraphs++;
            }
        }
        std::cout << "Perfect matching: " << perfectGraphs << "/" << ntests << std::endl;
    }
    std::cout << "Done" << std::endl;
}

int main (int argc, char *argv[]) {
    srand(std::time(0));
    hopcroft(500,1000);
    blossom(1000,1000);

}
