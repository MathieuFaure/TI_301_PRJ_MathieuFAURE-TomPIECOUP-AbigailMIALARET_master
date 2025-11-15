#ifndef __HASSE_H__
#define __HASSE_H__

#include "tarjan.h"

typedef struct s_link {
    t_class *from;
    t_class *to;
} t_link;

typedef struct s_link_array {
    t_link *links;
    int log_size;
} t_link_array;

t_link_array initLinkArray(t_adjacencyList *graph);
void removeTransitiveLinks(t_link_array *p_link_array);

/**
 * @brief Creates a link array from the given partition and graph.
 *
 * @param part The partition of the graph.
 * @param graph The adjacency list representation of the graph.
 * @return The created link array.
 */

#endif