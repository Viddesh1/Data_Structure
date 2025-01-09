// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program to generate the adjancency matrix.
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

#define MAX_VERTICES 100

void initializeMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    matrix[u][v] = 1; // Add edge u -> v
    matrix[v][u] = 1; // Uncomment for undirected graph
}

void printMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, e;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize the matrix with 0s
    initializeMatrix(adjacencyMatrix, n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v) one by one:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge to the matrix
        addEdge(adjacencyMatrix, u, v);
    }

    // Print the adjacency matrix
    printMatrix(adjacencyMatrix, n);

    return 0;
}

/*
OP:-

Admin@DESKTOP-7QU68H8 MINGW64 ~/Desktop/Data_Struct/Data_Structure (main)
$ gcc -g 10.cpp -o 10

Admin@DESKTOP-7QU68H8 MINGW64 ~/Desktop/Data_Struct/Data_Structure (main)
$ ./10
Enter the number of vertices: 4
Enter the number of edges: 3
Enter the edges (u v) one by one:
0 1
1 2
2 3
Adjacency Matrix:
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0
*/
