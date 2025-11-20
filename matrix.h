#ifndef MATRIX_H
#define MATRIX_H

#include "adjacencyList.h"
#include "tarjan.h"

typedef struct s_matrix {
    float **values;
    int n;
} t_matrix;

void displayMatrix(t_matrix *matrix);
t_matrix *createMatrix(t_adjacencyList* graph, int n);
t_matrix *createEmptyMatrix(int n);
t_matrix *copyValues(t_matrix *matrix);
t_matrix *multiply(t_matrix *matrix1, t_matrix *matrix2);
float difference(t_matrix *matrix1, t_matrix *matrix2);
t_matrix *createSubMatrix(t_matrix *matrix, t_partition *part, int compo_index);
t_matrix *getMn(t_matrix *matrix, int n);
float *getDistribution(const float *initialDistribution, t_matrix *matrix);
float *getMnDistribution(float *initialDistribution, t_matrix *matrix, int n);
t_matrix *getStationnaryMn(t_matrix *matrix);
float *getStationnaryDistribution(float *initialDistribution, t_matrix *matrix);
void displayDistribution(float *distribution, int size);
void displayStationnaryPartitionDistribution(t_matrix *matrix, t_partition *partition, float *initialDistribution);


#endif //MATRIX_H
