/*
*                   Временные затраты
* Хранить граф          O(V^2)
* Добавить вершину      O(V^2)
* Добавить ребро        O(1)
* Удалить вершину       O(V^2)
* Удалить ребро         O(1)
* Проверка на соседство O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define numVertices 7


struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* front;
};

void push(Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    if (stack->front != NULL) newNode->next = stack->front;
    stack->front = newNode;
}

int pop(Stack* stack) {
    if (stack->front == NULL) return -1;
    int data = stack->front->data;
    stack->front = stack->front->next;
    return data;
}

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode*front, *back;
};

void put(Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->back = newNode;
    }
    else {
        queue->back->next = newNode;
        queue->back = newNode;
    }
}

int get(Queue* queue) {
    if (queue->front == NULL) return -1;
    else {
        int data = queue->front->data;
        queue->front = queue->front->next;

        if (queue->front == NULL) {
            queue->back = NULL;
        }

        return data;
    }
}


struct Graph {
    int visited[numVertices];
    int adjMatrix[numVertices][numVertices];
};

// Функция для создания графа с numVertices вершинами
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < numVertices; i++) {
        graph->visited[i] = 0;
        for (int j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int x, int y) {
    if (x >= numVertices || y >= numVertices) return;
    graph->adjMatrix[x][y] = 1;
}

void removeEdge(Graph* graph, int x, int y) {
    if (x >= numVertices || y >= numVertices) return;
    graph->adjMatrix[x][y] = 0;
}

bool adjacent(Graph* graph, int x, int y) {
    if (x >= numVertices || y >= numVertices) return false;
    return graph->adjMatrix[x][y] == 1;
}

void BFS(Graph* graph, int vertex) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->back = NULL;

    printf("(%d)-", vertex);
    put(q, vertex);

    while (q->front != NULL)
    {
        int vert = get(q);
        for (int i = 0; i < numVertices; i++)
        {
            if (graph->adjMatrix[vert][i] == 1) {
                if (graph->visited[i] == 0) {
                    printf("(%d)-", i);
                    put(q, i);
                    graph->visited[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        graph->visited[i] = 0;
    }
    printf("\n");
}

void DFS(Graph* graph, int vertex) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->front = NULL;
    push(s, vertex);

    while (s->front != NULL)
    {
        int vert = pop(s);
        printf("(%d)-", vert);
        for (int i = 0; i < numVertices; i++)
        {
            if (graph->adjMatrix[vert][i] == 1) {
                if (graph->visited[i] == 0) {
                    push(s, i);
                    graph->visited[i] = 1;
                }
            }
        }
    }    
    for (int i = 0; i < numVertices; i++)
    {
        graph->visited[i] = 0;
    }
    printf("\n");
}

// Функция для печати графа
void printGraph(struct Graph* graph) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    Graph* graph;
    graph = createGraph();

    int input;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 2, 5);

    printGraph(graph);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", rand() % 10);
    }

    while (true)
    {
        printf("\n\n Обходы графа: ");
        printf("\n1 - в ширину, 2 - в глубину");
        scanf_s("%d", &input);

        if (input == 1) {
            BFS(graph, 0);
            input = 0;
        }
        if (input == 2) {
            DFS(graph, 0);
            input = 0;
        }
    }

    return 0;
}
