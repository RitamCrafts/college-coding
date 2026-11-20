#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

struct GraphNode {
    int data;
    struct GraphNode *next;
};

struct Graph {
    int numVertices;
    struct GraphNode **adjLists;
    int isDirected;
};

struct Queue {
    int front;
    int rear;
    int items[MAX_SIZE];
};

struct GraphNode *createNode(int val){
    struct GraphNode *newNode = (struct GraphNode *)malloc(sizeof(struct GraphNode));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int v, int isDirected){
    struct Graph *newGraph = malloc(sizeof(struct Graph));
    newGraph->numVertices = v;
    struct GraphNode **list = malloc(v * sizeof(struct GraphNode *));
    newGraph->adjLists = list;
    for(int i = 0; i<v; i++){
        newGraph->adjLists[i] = NULL;
    }

    newGraph->isDirected = isDirected;

    return newGraph;
}

struct GraphNode *insertBeginning(struct GraphNode *head, int val){
    struct GraphNode *newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }

    newNode->next = head;
    head = newNode;

    return head;
}

struct GraphNode *insertEnd(struct GraphNode *head, int val){
    struct GraphNode *newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    struct GraphNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void addEdge(struct Graph *graph, int source, int destination){
    if(graph->isDirected == 1){
        if(graph->adjLists[source] == NULL){
            graph->adjLists[source] = insertBeginning(graph->adjLists[source],destination);
        }else{
            graph->adjLists[source] = insertEnd(graph->adjLists[source],destination);
        }
    }else{
        if(graph->adjLists[source] == NULL){
            graph->adjLists[source] = insertBeginning(graph->adjLists[source],destination);
        }else{
            graph->adjLists[source] = insertEnd(graph->adjLists[source],destination);
        }

        if(graph->adjLists[destination] == NULL){
            graph->adjLists[destination] = insertBeginning(graph->adjLists[destination],source);
        }else{
            graph->adjLists[destination] = insertEnd(graph->adjLists[destination],source);
        }
    }
}

void init(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q){
    if(q->front == -1){
        return 1;
    }

    return 0;
}

int isFull(struct Queue *q){
    if(q->rear == MAX_SIZE -1){
        return 1;
    }

    return 0;
}

void enQueue(struct Queue *q, int val){
    if(isFull(q) == 1){
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = val;
}

int deQueue(struct Queue *q){
    if(isEmpty(q) == 1){
        return -1;
    }

    int poppedElement = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }


    return poppedElement;
}

void breadthFirstSearch(struct Graph *graph, int startVertex){
    struct Queue *q = malloc(sizeof(struct Queue));
    init(q);

    int vertices = graph->numVertices;
    int visited[vertices];
    int result[vertices];

    for(int i = 0; i<vertices; i++){
        visited[i] = 0;
    }

    visited[startVertex] = 1;
    enQueue(q,startVertex);


    int index = 0;
    while(!isEmpty(q)){
        int currentVertex = deQueue(q);
        result[index++] = currentVertex;

        struct GraphNode *temp = graph->adjLists[currentVertex];
        while(temp != NULL){
            int adjVertex = temp->data;
            if(visited[adjVertex] == 0){
                visited[adjVertex] = 1;
                enQueue(q, adjVertex);
            }

            temp = temp->next;
        }

    }

    printf("Result: \n");
    for(int i = 0; i<index; i++){
        printf("%d ",result[i]);
    }

    printf("\n");

}

void printList(struct GraphNode *head){
    struct GraphNode *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        if(temp->next != NULL){
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

void displayGraph(struct Graph *graph){
    for(int i = 0; i<graph->numVertices; i++){
        printf("Vertex %d: ",i);
        printList(graph->adjLists[i]);
    }
    printf("\n");
}

int main() {
    int v, e;
    int source, destination;
    int isDirected;

    struct Graph* graph = NULL;

    printf("Enter total number of vertices: ");
    scanf("%d", &v);

    printf("Enter total number of edges: ");
    scanf("%d", &e);

    printf("Enter Directed or not (0/1): ");
    scanf("%d", &isDirected);

    if (isDirected != 0 && isDirected != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    graph = createGraph(v, isDirected);

    for (int i = 0; i < e; i++) {
        printf("Enter source and destination (0 to %d): ", v - 1);
        scanf("%d %d", &source, &destination);

        if (source < 0 || source >= v || destination < 0 || destination >= v) {
            printf("Error: Vertex index out of bounds! Must be between 0 and %d.\n", v - 1);
            i--; 
            continue;
        }

        addEdge(graph, source, destination);
    }

    printf("\nAdjacency List:\n");
    displayGraph(graph);

    int startVertex;
    printf("Enter Start Vertex (0 to %d): ", v - 1);
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= v) {
        printf("Error: Start vertex out of bounds!\n");
        return 1;
    }

    breadthFirstSearch(graph, startVertex);

    return 0;
}