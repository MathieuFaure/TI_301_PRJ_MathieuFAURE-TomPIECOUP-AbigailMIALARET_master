#ifndef MATRIX_H
#define MATRIX_H

#include "adjacencyList.h"

void displayMatrix(float **matrix,int n);
float **createMatrix(t_adjacencyList* graph, int n);
float **createEmptyMatrix(t_adjacencyList* graph, int n);
float **copyValues(float **matrix, int n);
float **multiply(float **matrix1, float **matrix2, int n);
float difference(float **matrix1, float **matrix2, int n);

#endif //MATRIX_H
