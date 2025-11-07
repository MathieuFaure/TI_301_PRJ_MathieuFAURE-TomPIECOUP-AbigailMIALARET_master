#include <stdio.h>
#include "adjacencyList.h"

int main() {

    // PART 1 :

    // test for step 1 :

    t_adjacencyList *graph1 = readGraph("filename.txt");
    displayAdjacencyList(graph1);

    // test for step 2 :

    t_adjacencyList *graph2 = readGraph("filename.txt");
    markovGraphOrNot(graph2);

    // test for step 3 :

    t_adjacencyList *graph3 = readGraph("filename.txt");
    textFile(graph3);

    return 0;
}
