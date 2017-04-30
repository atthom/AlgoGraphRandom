
#include <cstdlib>
using std::srand;

#include <ctime>
using std::time;

#include "RandomBiGraph.h"
#include "BipartGraph.h"
#include "Hopcroft.h"
#include "Matrix.h"
#include "Hongrois.h"
#include "blossom/Graph.h"
#include "blossom/BlossomAlgo.h"

using namespace Blossom;

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

void blossom(unsigned int n, unsigned int ntests){
    std::cout << "Blossom" << std::endl;
    for (double p = 0.1; p < 0.9; p+=0.1) {
        std::cout << "p: " << p << std::endl;
        unsigned int perfectGraphs = 0;
        for (int i = 0; i < ntests; ++i) {
            Graph graph(n, p);
            std::cout << "Generated" << std::endl;
            BlossomAlgo b(graph);
            unsigned int matching = b.matching();
            std::cout << "matching: " << matching << std::endl;
            if(matching == n/2){
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

void testBlossom(){
    Graph graph;
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    graph.addNode(8);
    graph.addNode(9);
    graph.connect(0,1);
    graph.connect(0,2);
    graph.connect(1,2);
    graph.connect(1,3);
    graph.connect(3,4);
    graph.connect(4,5);
    graph.connect(2,6);
    graph.connect(6,5);
    graph.connect(6,7);
    graph.connect(7,8);
    graph.connect(7,9);
    graph.connect(8,9);
    BlossomAlgo b(graph);
    unsigned matching = b.matching();
}

int main (int argc, char *argv[]) {
    srand(time(0));
    hopcroft(500,1000);
    //blossom(1000,100);
    //testBlossom();
    //hongrois();
}
