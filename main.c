#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.h"
#include "tarjan.h"
#include "hasse.h"
#include "matrix.h"

int main() {
    // PART 1 :

    // test for step 1 :

    /*t_adjacencyList *graph1 = readGraph("data/exemple1.txt");
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

    /*t_adjacencyList *graph6 = readGraph("data/exemple_hasse1.txt");
    t_partition *partition6 = tarjan(graph6);
    t_link_array *linkArray6 = initLinkArray(graph6,partition6);
    displayCharacteristics(partition6, linkArray6);*/

    // PART 3 :

    // test for step 1 :

    /*t_adjacencyList *graph7 = readGraph("data/exemple_meteo.txt");
    t_matrix *matrix1 = createMatrix(graph7,graph7->size);
    t_matrix *M3 = getMn(matrix1,3);
    t_matrix *M7 = getMn(matrix1,7);

    printf("Matrix M :\n");
    displayMatrix(matrix1);

    printf("Matrix M3 :\n");
    displayMatrix(M3);

    printf("Matrix M7 :\n");
    displayMatrix(M7);

    // test for Mn

    t_matrix *stationnaryMn = getStationnaryMn(matrix1);
    printf("The stationnary Mn is :\n");
    displayMatrix(stationnaryMn);*/

    // test for step 2 :

    /*t_adjacencyList *graph8 = readGraph("data/exemple2.txt");
    t_matrix *matrix2 = createMatrix(graph8,graph8->size);
    t_partition *partition8 = tarjan(graph8);

    float *initialDistribution = malloc(5 * sizeof(float));

    initialDistribution[0] = 0.0f;
    initialDistribution[1] = 0.0f;
    initialDistribution[2] = 1.0f;
    initialDistribution[3] = 0.0f;
    initialDistribution[4] = 0.0f;

    displayStationnaryPartitionDistribution(matrix2,partition8,initialDistribution);*/

    return 0;
}
