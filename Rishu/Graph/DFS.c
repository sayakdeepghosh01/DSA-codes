#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int v) {
    s->vertices[++s->top] = v;
}

int pop(Stack *s) {
    return s->vertices[s->top--];
}

typedef struct {
    int **adjMatrix;
    int numVertices;
} Graph;

void initGraph(Graph *g, int numVertices) {
    g->numVertices = numVertices;
    g->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        g->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }
}

void addEdge(Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    // For undirected graph, add the following line
    // g->adjMatrix[dest][src] = 1;
}

void dfs(Graph *g, int startVertex) {
    Stack s;
    init(&s);
    int visited[MAX_VERTICES] = {0};

    push(&s, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&s)) {
        int currentVertex = pop(&s);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                push(&s, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    Graph g;
    int numVertices = 5;
    initGraph(&g, numVertices);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);

    printf("DFS starting from vertex 0: ");
    dfs(&g, 0);

    return 0;
}


//Explain-
// DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking.
// It uses a stack (or recursion) to keep track of vertices to visit next.