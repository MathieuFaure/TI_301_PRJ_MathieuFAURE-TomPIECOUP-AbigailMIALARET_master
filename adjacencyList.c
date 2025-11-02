#include <stdlib.h>
#include <stdio.h>
#include "adjacencyList.h"

t_adjacencyList* createEmptyAdjacencyList(int size) {
    t_adjacencyList* adj = (t_adjacencyList*)malloc(sizeof(t_adjacencyList));
    adj->size = size;
    adj->verticesList = (t_list*)malloc(size * sizeof(t_list));

    for (int i = 0; i < size; i++) {
        adj->verticesList[i] = createEmptyList();
    }

    return adj;
}

void displayAdjacencyList(t_adjacencyList* adj) {
    for (int i = 0; i < adj->size; i++) {
        printf("List for vertex %d: ", i+1);
        displayList(adj->verticesList[i]);
        printf("\n");
    }
}

t_adjacencyList* readGraph(const char *filename) {
    FILE *file = fopen(filename, "rt"); // read-only, text
    int nbvert, start, end;
    float proba;

    //declare the variable for the adjacency list
    t_adjacencyList* adj;

    if (file == NULL)
    {
        perror("Could not open file for reading");
        exit(EXIT_FAILURE);
    }
    // first line contains number of vertices
    if (fscanf(file, "%d", &nbvert) != 1)
    {
        perror("Could not read number of vertices");
        exit(EXIT_FAILURE);
    }

    //Initialise an empty adjacency list using the number of vertices
    adj = createEmptyAdjacencyList(nbvert);

    while (fscanf(file, "%d %d %f", &start, &end, &proba) == 3) {     // we obtain, for each line of the file, the values start, end and proba

        //Add the edge that runs from 'start' to ‘end’ with the probability 'proba' to the adjacency list
        addCell(&adj->verticesList[start-1], end, proba);
    }
    fclose(file);

    return adj;
}


void markovGraphOrNot(t_adjacencyList* adj) {
    for (int i = 0; i < adj->size; i++) {
        float sum = 0;
        t_cell *curr = adj->verticesList[i].head;
        while (curr != NULL) {
            sum += curr->proba;
            curr = curr->next;
        }

        if (sum < 0.99 || sum > 1.00) {
            printf("The graph is not a Markov graph. The sum of the probabilities of vertex %d is %f",i+1,sum);
            return;
        }
    }
    printf("The graph is a Markov graph");
}


void textFile(t_adjacencyList* adj) {
    FILE *file = fopen("textFile.txt", "wt");

    fprintf(file, "---\nconfig:\n\tlayout: elk\n\ttheme: neo\n\tlook: neo\n---\n\nflowchart LR\n");

    for (int i = 0; i < adj->size; i++) {
        fprintf(file,"%s((%d))\n",getID(i+1),i+1);
    }

    for (int i = 0; i < adj->size; i++) {
        t_cell *curr = adj->verticesList[i].head;
        while (curr != NULL) {
            printf("arrivalVertex : %d et la lettre : %s\n",curr->arrivalVertex,getID(curr->arrivalVertex));
            fprintf(file,"\n%s -->|%.2f|",getID(i+1),curr->proba);
            fprintf(file,"%s",getID(curr->arrivalVertex));
            curr = curr->next;
        }
    }

    fclose(file);
}