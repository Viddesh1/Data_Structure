// ------------------------------------------------------------------------------------------------------------------------------------
// Write a program for shortest path diagram (dijkstra algorithm)
// ------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance
int findMinDistance(int distance[], int visited[], int n) {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int distance[MAX_VERTICES]; // Distance array
    int visited[MAX_VERTICES] = {0}; // Visited array

    // Initialize distances
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
    }
    distance[src] = 0; // Distance to source is 0

    for (int count = 0; count < n - 1; count++) {
        int u = findMinDistance(distance, visited, n); // Pick the minimum distance vertex
        visited[u] = 1;

        // Update the distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int n, src;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}


/*
OP:-

Admin@DESKTOP-7QU68H8 MINGW64 ~/Desktop/Data_Struct/Data_Structure (main)
$ gcc -g 11.cpp -o 11

Admin@DESKTOP-7QU68H8 MINGW64 ~/Desktop/Data_Struct/Data_Structure (main)
$ ./11
Enter the number of vertices: 5
Enter the adjacency matrix (use 0 for no edge):
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
Enter the source vertex: 0
Vertex  Distance from Source
0       0
1       8
2       9
3       7
4       5
*/
