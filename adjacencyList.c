#include <stdlib.h>
#include <stdio.h>
#include "adjacencyList.h"

t_adjacencyList* createEmptyAdjacencyList(int size) {
    t_adjacencyList* adj = (t_adjacencyList*)malloc(sizeof(t_adjacencyList));
    adj->size = size;
    adj->verticesList = (t_list*)malloc(size * sizeof(t_list));

    for (int i = 0; i < size; i++) {
        adj->verticesList[i] = createEmptyList();
    }

    return adj;
}

void displayAdjacencyList(t_adjacencyList* adj) {
    for (int i = 0; i < adj->size; i++) {
        printf("List for vertex %d: ", i+1);
        displayList(adj->verticesList[i]);
        printf("\n");
    }
}