#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMatrix(t_matrix *matrix) {
	for (int i = 0; i < matrix->n; i++) {
        printf("[");
        for (int j = 0; j < matrix->n-1; j++) {
        	printf(" %.2f ;", matrix->values[i][j]);
        }
        printf(" %.2f ]\n", matrix->values[i][matrix->n-1]);
    }
    printf("\n");
}


t_matrix *createEmptyMatrix(int n) {
    t_matrix *matrix = malloc(sizeof(t_matrix));
    matrix->values = malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        matrix->values[i] = malloc(n * sizeof(float));
    }

    matrix->n = n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix->values[i][j] = 0;
        }
    }

    return matrix;
}



t_matrix *createMatrix(t_adjacencyList* graph, int n) {
    t_matrix *matrix = createEmptyMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	int inList = 0;
            t_cell *curr = graph->verticesList[i].head;
            while (curr != NULL) {
				if (curr->arrivalVertex-1 == j) {
                	matrix->values[i][j] = curr->proba;
                    inList = 1;
				}
                curr = curr->next;
            }
            if (!inList) {
            	matrix->values[i][j] = 0;
            }
        }
    }

    return matrix;
}



t_matrix *copyValues(t_matrix *matrix) {
    t_matrix *copyMatrix = createEmptyMatrix(matrix->n);

    for (int i = 0; i < matrix->n; i++) {
        for (int j = 0; j < matrix->n; j++) {
            copyMatrix->values[i][j] = matrix->values[i][j];
        }
    }

    return copyMatrix;
}


t_matrix *multiply(t_matrix *matrix1, t_matrix *matrix2) {
	t_matrix *matrix = createEmptyMatrix(matrix1->n);

    for (int i = 0; i < matrix->n; i++) {
    	for (int j = 0; j < matrix->n; j++) {
        	for (int k = 0; k < matrix->n; k++) {
            	matrix->values[i][j] = matrix->values[i][j] + matrix1->values[i][k] * matrix2->values[k][j];
        	}
    	}
    }

    return matrix;
}


float difference(t_matrix *matrix1, t_matrix *matrix2) {
    float diff = 0;

    for (int i = 0; i < matrix1->n; i++) {
    	for (int j = 0; j < matrix1->n; j++) {
        	diff += fabsf(matrix1->values[i][j] - matrix2->values[i][j]);
    	}
    }

    return diff;
}


t_matrix *createSubMatrix(t_matrix *matrix, t_partition *part, int compo_index) {
    t_class *class = &part->classes[compo_index];
    int n = class->nbVertices;
    t_matrix *subMatrix = createEmptyMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            subMatrix->values[i][j] = matrix->values[class->vertices[i]->id-1][class->vertices[j]->id-1];
        }
    }

    return subMatrix;
}


t_matrix *getMn(t_matrix *matrix, int n) {
    t_matrix *Mn = copyValues(matrix);
    for (int i = 0; i < n-1; i++) {
        Mn = multiply(Mn,matrix);
    }

    return Mn;
}


float *getDistribution(const float *initialDistribution, t_matrix *matrix) {
    float *finalDistribution = malloc(sizeof(float) * matrix->n);
    for (int i = 0; i < matrix->n; i++) {
        float sum = 0;
        for (int j = 0; j < matrix->n; j++) {
            sum += initialDistribution[j] * matrix->values[i][j];
        }
        finalDistribution[i] = sum;
    }

    return finalDistribution;
}


float *getMnDistribution(float *initialDistribution, t_matrix *matrix, int n) {
    t_matrix *Mn = getMn(matrix,n);
    return getDistribution(initialDistribution, Mn);
}

t_matrix *getStationnaryMn(t_matrix *matrix) {
    t_matrix *Mn = copyValues(matrix);
    t_matrix * MN = multiply(Mn,matrix);
    while (difference(MN,Mn) > 0.01) {
        Mn = multiply(Mn,matrix);
        MN = multiply(MN,matrix);
    }
    return MN;
}

float *getStationnaryDistribution(float *initialDistribution, t_matrix *matrix) {
    t_matrix *stationnaryMn = getStationnaryMn(matrix);
    return getDistribution(initialDistribution, stationnaryMn);
}

void displayDistribution(float *distribution, int size) {
    printf("[");
    for (int i = 0; i < size-1; i++) {
        printf(" %.2f ;",distribution[i]);
    }
    printf(" %.2f ]\n", distribution[size-1]);
}


void displayStationnaryPartitionDistribution(t_matrix *matrix, t_partition *partition, float *initialDistribution) {
    for (int i = 0; i < partition->nbClasses; i++) {
        printf("%s stationnary distribution : ",partition->classes[i].name);
        t_matrix *subMatrix = createSubMatrix(matrix,partition,i);
        displayDistribution(getStationnaryDistribution(initialDistribution,subMatrix), subMatrix->n);
    }
}









