#include <stdio.h>
#include "adjacencyList.h"

int main() {

    // PART 1 :

    // test for step 1 :
    t_adjacencyList *graph = readGraph("data/exemple_valid_step3.txt");
    displayAdjacencyList(graph);
    textFile(graph);

    return 0;
}
