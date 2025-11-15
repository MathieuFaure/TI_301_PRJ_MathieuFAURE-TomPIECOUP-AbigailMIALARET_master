#include <malloc.h>
#include "hasse.h"

t_class **arrayClass(t_adjacencyList *graph, t_partition *partition) {
	t_class **verticesClass = malloc(graph->size * sizeof(t_class*));

    for (int i = 0; i < graph->size; i++) {
        verticesClass[i] = NULL;
    }

    for (int i = 0; i < partition->nbClasses; i++) {
    	t_class *class = &partition->classes[i];
    	for (int j = 0; j < class->nbVertices; j++) {
        	int id = class->vertices[j]->id - 1;
            verticesClass[id] = class;
    	}
    }

    return verticesClass;
}

t_link_array initLinkArray(t_adjacencyList *graph) {
    t_partition *partition = tarjan(graph);
	t_class **array = arrayClass(graph,partition);

    t_link_array linkArray;
    linkArray.links = malloc(NBMAX * sizeof(t_link));   // enough for now
    linkArray.log_size = 0;

    for (int i = 0; i < graph->size; i++) {
		t_class *Ci = array[i];
        t_cell *curr = graph->verticesList[i].head;
        while (curr != NULL) {
        	int j = curr->arrivalVertex - 1;

            t_class *Cj = array[j];

            if (Ci != Cj) {

                int exists = 0;
                for (int k = 0; k < linkArray.log_size; k++) {
                    if (linkArray.links[k].from == Ci && linkArray.links[k].to == Cj) {
                        exists = 1;
                        break;
                    }
                }

                if (!exists) {
                    linkArray.links[linkArray.log_size].from = Ci;
                    linkArray.links[linkArray.log_size].to = Cj;
                    linkArray.log_size++;
                }
            }

            curr = curr->next;
        }
    }

    free(array);
    return linkArray;
}

void removeTransitiveLinks(t_link_array *p_link_array)
{
    int i = 0;
    while (i < p_link_array->log_size)
    {
        t_link link1 = p_link_array->links[i];
        int j = 0;
        int to_remove = 0;
        while (j < p_link_array->log_size && !to_remove)
        {
            if (j != i)
            {
                t_link link2 = p_link_array->links[j];
                if (link1.from == link2.from)
                {
                    // look for a link from link2.to to link1.to
                    int k = 0;
                    while (k < p_link_array->log_size && !to_remove)
                    {
                        if (k != j && k != i)
                        {
                            t_link link3 = p_link_array->links[k];
                            if ((link3.from == link2.to) && (link3.to == link1.to))
                            {
                                to_remove = 1;
                            }
                        }
                        k++;
                    }
                }
            }
            j++;
        }
        if (to_remove)
        {
            // remove link1 by replacing it with the last link
            p_link_array->links[i] = p_link_array->links[p_link_array->log_size - 1];
            p_link_array->log_size--;
        }
        else
        {
            i++;
        }
    }
}
