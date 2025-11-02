#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to compare edges for qsort
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm using an edge list
void primMST(struct Edge edges[], int edgeCount) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    int mstSet[V]; // To represent the set of vertices included in the MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;      // Make the key 0 so that this vertex is picked first
    parent[0] = -1;  // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update the key value and parent index of the adjacent vertices of the picked vertex
        for (int i = 0; i < edgeCount; i++) {
            // Check if the edge connects to the picked vertex
            if (edges[i].src == u && mstSet[edges[i].dest] == 0) {
                if (edges[i].weight < key[edges[i].dest]) {
                    parent[edges[i].dest] = u;
                    key[edges[i].dest] = edges[i].weight;
                }
            } else if (edges[i].dest == u && mstSet[edges[i].src] == 0) {
                if (edges[i].weight < key[edges[i].src]) {
                    parent[edges[i].src] = u;
                    key[edges[i].src] = edges[i].weight;
                }
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
}

int main() {
    // Example graph represented as an edge list
    struct Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // Call the Prim's algorithm function
    primMST(edges, edgeCount);

    return 0;
}

