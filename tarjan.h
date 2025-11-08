#ifndef TARJAN_H
#define TARJAN_H
#define NBMAX 50
#include "adjacencyList.h"

typedef struct s_tarjanVertex {
    int id;
    int index;
    int accessibleNumber;
    int onStack;
} t_tarjanVertex;

typedef struct s_class {
    char name[10];
    t_tarjanVertex **vertices;
    int nbVertices;
} t_class;

typedef struct s_partition {
    t_class *classes;
    int nbClasses;
} t_partition;

typedef struct s_stack {
    t_tarjanVertex values[NBMAX];
    int nbValues;
} t_stack;

t_tarjanVertex* initTarjanVertices(t_adjacencyList*);

#endif //TARJAN_H
