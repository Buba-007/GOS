/*
*                   Временные затраты
* Хранить граф          O(V + E)
* Добавить вершину      O(1)
* Добавить ребро        O(1)
* Удалить вершину       O(E)
* Удалить ребро         O(V)
* Проверка на соседство O(V)
*/


#include <stdio.h>
#include <stdlib.h>

#define numVertices 7

// Структура для представления узла в списке смежности (ссылка в списке смежности задаёт РЕБРО)
struct Node {
    int vertex;
    struct Node* next;
};

// Структура для представления графа через списки смежности
struct Graph {
    int visited[numVertices];
    struct Node* verticesLists[numVertices];
};

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front, * rear;
};

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* front;
};

// Функция для создания нового узла
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {

    if (q->front == NULL) 
        return -1;

    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) 
        q->rear = NULL;

    free(temp);
    return data;
}

struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->front = NULL;
    return s;
}

void push(Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;

    newNode->next = stack->front;
    stack->front = newNode;
}

int pop(Stack* stack) {
    if (stack->front == NULL) {
        return -1;
    }

    struct StackNode* temp = stack->front;
    int data = temp->data;
    stack->front = temp->next;
    free(temp);

    return data;
}

// Функция для создания графа с numVertices вершинами
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (int i = 0; i < numVertices; i++) {
        graph->verticesLists[i] = NULL;
    }

    return graph;
}

bool adjacent(struct Graph* graph, int current, int neighbour) {
	struct Node* temp = graph->verticesLists[current];
	while (temp) {
		if (temp->vertex == neighbour)
			return true;
		temp = temp->next;
	}
	return false;
}

// Функция для добавления ребра в граф
void addEdge(struct Graph* graph, int current, int neighbour) {
    // Добавляем ребро от src к dest
    struct Node* newNode = createNode(neighbour);
    newNode->next = graph->verticesLists[current];
    graph->verticesLists[current] = newNode;

    // Добавляем ребро от dest к src (если граф неориентированный)
    // struct Node* newNode = createNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

bool removeEdge(struct Graph* graph, int current, int neighbour) {
    struct Node* pred = NULL;
    struct Node* curr = graph->verticesLists[current];

    //// Первый элемент списка
    if (curr != NULL && curr->vertex == neighbour) {
        graph->verticesLists[current] = curr->next;
        free(curr);
        return true;
    }

    // Поиск удаляемого узла в списке смежности
    while (curr != NULL) {
        if (curr->vertex == neighbour) {
            pred->next = curr->next; // Изменяем указатель на следующий узел у предыдущего узла
            free(curr); // Освобождаем память удаляемого узла
            return true;
        }
        pred = curr;
        curr = curr->next;
    }

    return false; // Ребро не найдено
}

void BFS(struct Graph* graph, int startVertex) {
    // Создаем новую очередь для посещенных вершин
    struct Queue* q = createQueue();

    // Помечаем начальную вершину как посещенную и добавляем ее в очередь
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    // Пока очередь не пуста
    while (q->front != NULL) {
        // Извлекаем текущую вершину из очереди
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        // Получаем список смежных вершин текущей вершины
        struct Node* temp = graph->verticesLists[currentVertex];

        // Просматриваем все смежные вершины
        while (temp != NULL) {
            int adjVertex = temp->vertex;

            // Если смежная вершина не была посещена ранее
            if (graph->visited[adjVertex] != 1) {
                // Помечаем ее как посещенную и добавляем в очередь
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next; // Переходим к следующей смежной вершине
        }
    }
    for (int i = 0; i < numVertices; i++) {
        graph->visited[i] = 0;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    // Тоже со стеком
    struct Stack* s = createStack();

    graph->visited[startVertex] = 1;
    push(s, startVertex);

    while (s->front != NULL) {
        int currentVertex = pop(s);
        printf("Visited %d\n", currentVertex);
        struct Node* temp = graph->verticesLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] != 1) {
                graph->visited[adjVertex] = 1;
                push(s, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Функция для печати графа
void printGraph(struct Graph* graph) {
    for (int v = 0; v < numVertices; v++) {
        struct Node* temp = graph->verticesLists[v];
        printf("Adj list of vert %d\n", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph();
    /*addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);*/

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 2, 5);

    printGraph(graph);

   /* if (adjacent(graph, 0, 1)) {
        printf("Found \n");
    }
    else {
        printf("Not found \n");
    }

    if (adjacent(graph, 0, 3)) {
        printf("Found \n");
    }
    else {
        printf("Not found \n");
    }

    if (removeEdge(graph, 1, 4)) {
        printf("Removed \n");
    }
    else {
        printf("Not removed \n");
    }
    
    printGraph(graph);

    if (removeEdge(graph, 0, 3)) {
        printf("Removed \n");
    }
    else {
        printf("Not removed \n");
    }*/

    printf("\n");
    BFS(graph, 0);
    printf("\n");
    DFS(graph, 0);

    return 0;
}