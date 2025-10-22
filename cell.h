#ifndef CELL_H
#define CELL_H

typedef struct s_cell {
    int arrivalVertex;
    float proba;
    struct s_cell *next;
} t_cell;

t_cell* createCell(int arrivalVertex, float proba);

#endif //CELL_H
