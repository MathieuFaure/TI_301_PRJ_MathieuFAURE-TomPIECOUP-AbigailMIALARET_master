#include <stdio.h>
#include "list.h"

t_list createEmptyList() {
    t_list newList;
    newList.head = NULL;
    return newList;
}

void addCell(t_list *list, int arrivalVertex, float proba) {
    t_cell *newCell = createCell(arrivalVertex, proba);
    newCell->next = list->head;
    list->head = newCell;
}

void displayList(t_list list) {
    printf("[head @] -> ");
    t_cell *curr = list.head;
    if (curr == NULL) {
        printf("NULL\n");
    } else {
        while (curr->next != NULL) {
            printf("(%d, %f) @-> ", curr->arrivalVertex, curr->proba);
            curr = curr->next;
        }
        printf("(%d, %f)", curr->arrivalVertex, curr->proba);
    }

}
