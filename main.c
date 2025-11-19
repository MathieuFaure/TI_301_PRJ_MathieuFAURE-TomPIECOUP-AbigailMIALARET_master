#include <stdio.h>
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
    float **matrix1 = createMatrix(graph7,graph7->size);
    float **M3 = createMatrix(graph7,graph7->size);
    float **M7 = createMatrix(graph7,graph7->size);

    printf("Matrix M :\n");
    displayMatrix(matrix1,graph7->size);

    for(int i=0;i<2;i++) {
        M3 = multiply(matrix1,M3,graph7->size);
    }

    printf("Matrix M3 :\n");
    displayMatrix(M3,graph7->size);

    for(int i=0;i<6;i++) {
        M7 = multiply(matrix1,M7,graph7->size);
    }

    printf("Matrix M7 :\n");
    displayMatrix(M7,graph7->size);*/

    // test for Mn

    /*t_adjacencyList *graph8 = readGraph("data/exemple_meteo.txt");
    float **matrix2 = createMatrix(graph8,graph8->size);
    float **Mn = createMatrix(graph8,graph8->size);
    float **MN = multiply(matrix2,Mn,graph8->size);

    int n = 2;

    while (difference(MN,Mn,graph8->size) >= 0.01) {
        MN = multiply(MN,matrix2,graph8->size);
        Mn = multiply(Mn,matrix2,graph8->size);
        n += 1;
    }

    printf("Mn for which the difference between Mn and Mn-1 is less than 0.01 is M%d",n);*/



    return 0;
}
