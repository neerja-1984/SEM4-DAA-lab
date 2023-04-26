#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define a struct for the adjacency list
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Define a struct for the graph
typedef struct graph {
    Node* adj_list[MAX_VERTICES];
    int num_vertices;
} Graph;

// Create a new node with the given vertex number
Node* create_node(int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

// Add an edge to the graph
void add_edge(Graph* g, int src, int dest) {
    Node* new_node = create_node(dest);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

// Check if a given set of vertices is a vertex cover
bool is_vertex_cover(Graph* g, bool cover[]) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (!cover[i]) {
            Node* curr = g->adj_list[i];
            while (curr != NULL) {
                if (!cover[curr->vertex]) {
                    return false;
                }
                curr = curr->next;
            }
        }
    }
    return true;
}

// Find the size of the minimum vertex cover using a brute force algorithm
int find_minimum_vertex_cover(Graph* g) {
    bool cover[MAX_VERTICES] = {false};
    int min_size = g->num_vertices;
    for (int i = 0; i < (1 << g->num_vertices); i++) {
        int size = 0;
        for (int j = 0; j < g->num_vertices; j++) {
            if (i & (1 << j)) {
                cover[j] = true;
                size++;
            } else {
                cover[j] = false;
            }
        }
        if (is_vertex_cover(g, cover) && size < min_size) {
            min_size = size;
        }
    }
    return min_size;
}

// Main function
int main() {
    Graph g;
    g.num_vertices = 0;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &g.num_vertices);
    for (int i = 0; i < g.num_vertices; i++) {
        g.adj_list[i] = NULL;
    }
    int num_edges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i+1);
        scanf("%d %d", &src, &dest);
        add_edge(&g, src, dest);
    }
    int min_size = find_minimum_vertex_cover(&g);
    printf("The size of the minimum vertex cover is %d.\n", min_size);
    return 0;
}

