#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMatrix(float **matrix,int n) {
	for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < n-1; j++) {
        	printf(" %.2f ;", matrix[i][j]);
        }
        printf(" %.2f ]\n", matrix[i][n-1]);
    }
    printf("\n");
}

float **createMatrix(t_adjacencyList* graph, int n) {
    float **matrix = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	int inList = 0;
            t_cell *curr = graph->verticesList[i].head;
            while (curr != NULL) {
				if (curr->arrivalVertex-1 == j) {
                	matrix[i][j] = curr->proba;
                    inList = 1;
				}
                curr = curr->next;
            }
            if (!inList) {
            	matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

float **createEmptyMatrix(t_adjacencyList* graph, int n) {
    float **matrix = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

float **copyValues(float **matrix, int n) {
	float **copyMatrix = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        copyMatrix[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copyMatrix[i][j] = matrix[i][j];
        }
    }

    return copyMatrix;
}


float **multiply(float **matrix1, float **matrix2, int n) {
	float **matrix = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
    	matrix[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
        	for (int k = 0; k < n; k++) {
            	matrix[i][j] = matrix[i][j] + matrix1[i][k] * matrix2[k][j];
        	}
    	}
    }

    return matrix;
}


float difference(float **matrix1, float **matrix2, int n) {
    float diff = 0;

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
        	diff += fabs(matrix1[i][j] - matrix2[i][j]);
    	}
    }

    return diff;
}