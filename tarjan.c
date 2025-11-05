#include <stdio.h>
#include <stdlib.h>
#include "tarjan.h"

t_tarjanVertex* initTarjanVertices(t_adjacencyList* adj) {
    t_tarjanVertex* vertices = malloc(adj->size * sizeof(t_tarjanVertex));
    for (int i = 0; i < adj->size; i++) {
        vertices[i].id = i + 1;
        vertices[i].index = -1;
        vertices[i].accessibleNumber = -1;
        vertices[i].onStack = 0;
    }
    return vertices;
}