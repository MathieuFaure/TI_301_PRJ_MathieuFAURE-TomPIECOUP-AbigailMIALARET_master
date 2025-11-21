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
    for (int j = 0; j < matrix->n; j++) {
        float sum = 0;
        for (int i = 0; i < matrix->n; i++) {
            sum += initialDistribution[i] * matrix->values[i][j];
        }
        finalDistribution[j] = sum;
    }

    return finalDistribution;
}


float *getMnDistribution(float *initialDistribution, t_matrix *matrix, int n) {
    t_matrix *Mn = getMn(matrix,n);
    return getDistribution(initialDistribution, Mn);
}

t_matrix *getStationaryMn(t_matrix *matrix) {
    t_matrix *Mn = copyValues(matrix);
    t_matrix * MN = multiply(Mn,matrix);
    while (difference(MN,Mn) > 0.01) {
        Mn = multiply(Mn,matrix);
        MN = multiply(MN,matrix);
    }
    return MN;
}

float *getStationaryDistribution(float *initialDistribution, t_matrix *matrix) {
    t_matrix *stationaryMn = getStationaryMn(matrix);
    return getDistribution(initialDistribution, stationaryMn);
}

void displayDistribution(float *distribution, int size) {
    printf("[");
    for (int i = 0; i < size-1; i++) {
        printf(" %.2f ;",distribution[i]);
    }
    printf(" %.2f ]\n", distribution[size-1]);
}


void displayStationaryPartitionDistribution(t_matrix *matrix, t_partition *partition, float *initialDistribution) {
    displayPartition(partition);
    for (int i = 0; i < partition->nbClasses; i++) {

        t_matrix *subMatrix = createSubMatrix(matrix,partition,i);

        int period = getPeriod(subMatrix);

        if (period > 1) {
            printf("%s : period = %d -> no stationary distribution.\n", partition->classes[i].name, period);
        } else {
            printf("%s stationary distribution : ",partition->classes[i].name);

            float *dist = getStationaryDistribution(initialDistribution, subMatrix);
            displayDistribution(dist, subMatrix->n);
            free(dist);
        }
        for (int r = 0; r < subMatrix->n; r++) {
            free(subMatrix->values[r]);
        }
        free(subMatrix->values);
        free(subMatrix);
    }
}



int gcd(int *vals, int nbvals) {
    if (nbvals == 0) return 0;
    int result = vals[0];
    for (int i = 1; i < nbvals; i++) {
        int a = result;
        int b = vals[i];
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        result = a;
    }
    return result;
}

int getPeriod(t_matrix *sub_matrix) {
    int n = sub_matrix->n;
    int *periods = malloc(n * sizeof(int));
    int period_count = 0;

    t_matrix *power_matrix = copyValues(sub_matrix);

    for (int k = 1; k <= n; k++)
    {
        int diag_nonzero = 0;
        for (int i = 0; i < n; i++) {
            if (power_matrix->values[i][i] > 0.0f)
            {
                diag_nonzero = 1;
            }
        }

        if (diag_nonzero) {
            periods[period_count] = k;
            period_count++;
        }

        t_matrix *new_power = multiply(power_matrix, sub_matrix);
        power_matrix = new_power;
    }

    int period = gcd(periods, period_count);
    free(periods);

    for (int i = 0; i < n; i++) {
        free(power_matrix->values[i]);
    }
    free(power_matrix->values);
    free(power_matrix);

    return period;
}


void displayPartitionPeriods(t_partition *partition, t_matrix *matrix) {
    for (int i = 0; i < partition->nbClasses; i++) {
        printf("%s period : ",partition->classes[i].name);
        t_matrix *subMatrix = createSubMatrix(matrix,partition,i);
        printf("%d\n", getPeriod(subMatrix));

        for (int r = 0; r < subMatrix->n; r++) {
            free(subMatrix->values[r]);
        }
        free(subMatrix->values);
        free(subMatrix);
    }
}




