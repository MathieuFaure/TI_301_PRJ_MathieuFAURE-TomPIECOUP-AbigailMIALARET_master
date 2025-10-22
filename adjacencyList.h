#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "list.h"

typedef struct s_adjacencyList {
    t_list* verticesList;
    int size;
} t_adjacencyList;

#endif //ADJACENCYLIST_H
