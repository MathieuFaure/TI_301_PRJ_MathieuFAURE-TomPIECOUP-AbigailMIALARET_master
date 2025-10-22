#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "list.h"

typedef struct s_adjacencyList {
    t_list* verticesList;
    int size;
} t_adjacencyList;

t_adjacencyList* createEmptyAdjacencyList(int size);
void displayAdjacencyList(t_adjacencyList* adj);
t_adjacencyList* readGraph(const char *filename);


#endif //ADJACENCYLIST_H
