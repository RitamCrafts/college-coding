#include <stdio.h>
#include <stdlib.h>

struct GraphNode{
    int data;
    struct GraphNode *next;
};

struct Graph {
    int numVertices;
    struct GraphNode **adjLists;
    int isDirected;
};

struct GraphNode *createNode(int val){
    struct GraphNode *newNode = (struct GraphNode *)malloc(sizeof(struct GraphNode *));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

struct Graph *createGraph(int v, int isDirected){
    struct Graph *newGraph = malloc(sizeof(struct Graph));
    newGraph->numVertices = v;
    struct GraphNode **list = malloc(v*sizeof(struct GraphNode *));
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
        printf("Enter source and destination: ");
        scanf("%d %d", &source, &destination);

        addEdge(graph, source, destination);
    }

    printf("\nAdjacency List:\n");
    displayGraph(graph);

    return 0;
}