#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Subset {
    int parent, rank;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int index, int src, int dest, int weight) {
    graph->edges[index].src = src;
    graph->edges[index].dest = dest;
    graph->edges[index].weight = weight;
}

// Function to find the subset of an element i (uses path compression technique)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to do union of two subsets x and y (uses union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Union by rank
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function for qsort to sort edges by weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to perform Kruskal's algorithm to find MST
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];  // Array to store the result MST
    int e = 0;  // Count of edges in MST
    int i = 0;  // Index variable to traverse edges

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Step 2: Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 3: Process edges, adding them to the MST if they don't form a cycle
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it in the result
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Step 4: Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
    }

    // Free the allocated memory for subsets
    free(subsets);
}

// Main function
int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    struct Graph* graph = createGraph(V, E);

    // Adding edges to the graph
    addEdge(graph, 0, 0, 1, 2);
    addEdge(graph, 1, 0, 2, 3);
    addEdge(graph, 2, 1, 2, 1);
    addEdge(graph, 3, 1, 3, 4);
    addEdge(graph, 4, 2, 3, 5);

    // Perform Kruskal's algorithm to find the MST
    kruskalMST(graph);

    // Free allocated memory
    free(graph->edges);
    free(graph);
return 0;
}

