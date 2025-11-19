#include <stdio.h>
#include "adjacencyList.h"
#include "tarjan.h"
#include "hasse.h"

int main() {

    // PART 1 :

    // test for step 1 :

    /*t_adjacencyList *graph1 = readGraph("filename.txt");
    displayAdjacencyList(graph1);*/

    // test for step 2 :

    /*t_adjacencyList *graph2 = readGraph("filename.txt");
    markovGraphOrNot(graph2);*/

    // test for step 3 :

    /*t_adjacencyList *graph3 = readGraph("filename.txt");
    textFile(graph3);*/

    // PART 2 :

    // test for step 1 :

    /*t_adjacencyList *graph4 = readGraph("data/exemple2.txt");
    displayPartition(tarjan(graph4));*/

    // test for step 2 :

    /*t_adjacencyList *graph5 = readGraph("data/exemple_hasse1.txt");
    t_partition *partition5 = tarjan(graph5);
    t_link_array *linkArray5 = initLinkArray(graph5,partition5);
    textFileHasse(partition5, linkArray5);*/

    // test for step 3 :

    t_adjacencyList *graph6 = readGraph("data/exemple_hasse1.txt");
    t_partition *partition6 = tarjan(graph6);
    t_link_array *linkArray6 = initLinkArray(graph6,partition6);
    displayCharacteristics(partition6, linkArray6);

    return 0;
}
