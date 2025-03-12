#include <stdio.h>
#include <limits.h>

#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int n, int graph[V][V]) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick minimum weight edge
    int mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 to pick it first
    parent[0] = -1; // First node is always the root of MST

    // MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = 1;

        // Update key value and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update key only if graph[u][v] is non-zero, v is not in mstSet,
            // and the new weight is smaller than the current key
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, V, graph);
}

int main() {
    /* Let us create the following graph:
           2    3
       (0)--(1)--(2)
        |   / \   |
       6|  8   5  |7
        | /     \ |
       (3)-------(4)
            9
    */
    int graph[V][V] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };

    // Run Prim's algorithm
    primMST(graph);

    return 0;
}
