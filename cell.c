#include <stdlib.h>
#include "cell.h"

t_cell* createCell(int arrivalVertex, float proba) {
    t_cell* newCell = (t_cell*)malloc(sizeof(t_cell));
    newCell->arrivalVertex = arrivalVertex;
    newCell->proba = proba;
    newCell->next = NULL;
    return newCell;
}