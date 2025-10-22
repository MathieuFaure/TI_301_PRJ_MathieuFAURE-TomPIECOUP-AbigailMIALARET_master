#ifndef LIST_H
#define LIST_H
#include "cell.h"

typedef struct s_list {
    t_cell* head;
} t_list;

t_list createEmptyList();
void addCell(t_list *list, int arrivalVertex, float proba);
void displayList(t_list list);

#endif //LIST_H
