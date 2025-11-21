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
t_matrix *getStationaryMn(t_matrix *matrix);
float *getStationaryDistribution(float *initialDistribution, t_matrix *matrix);
void displayDistribution(float *distribution, int size);
void displayStationaryPartitionDistribution(t_matrix *matrix, t_partition *partition, float *initialDistribution);
int gcd(int *vals, int nbvals);
int getPeriod(t_matrix *sub_matrix);
void displayPartitionPeriods(t_partition *partition, t_matrix *matrix);


#endif //MATRIX_H
