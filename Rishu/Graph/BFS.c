#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int v) {
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->vertices[q->rear] = v;
}

int dequeue(Queue *q) {
    int v = q->vertices[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return v;
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

void bfs(Graph *g, int startVertex) {
    Queue q;
    init(&q);
    int visited[MAX_VERTICES] = {0};

    enqueue(&q, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] && !visited[i]) {
                enqueue(&q, i);
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

    printf("BFS starting from vertex 0: ");
    bfs(&g, 0);

    return 0;
}


// Explain: 

// BFS is a graph traversal algorithm that explores all the vertices in the graph at the present depth before moving to the vertices at the next depth level.
// It uses a queue to keep track of vertices to visit next.


