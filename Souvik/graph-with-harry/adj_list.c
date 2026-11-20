#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Graph{
    int numVeritces;
    struct Node **adjlist;
    int isDirected;
};

struct Node *createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int v, int isDirected){
    struct Graph *newGraph = malloc(sizeof(struct Graph));
    newGraph->numVeritces = v;
    newGraph->isDirected = isDirected;

    newGraph->adjlist = malloc(v*sizeof(struct Node *));
    for(int i = 0; i<newGraph->numVeritces; i++){
        newGraph->adjlist[i] = NULL;
    }

    return newGraph;
}

struct Node *insertBeginning(struct Node *head,int val){
    struct Node *newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *insertEnd(struct Node *head, int val){
    struct Node *newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void addEdge(struct Graph *graph,int source, int dest){
    if(graph->isDirected == 1){
        if(graph->adjlist[source] == NULL){
            graph->adjlist[source] = insertBeginning(graph->adjlist[source],dest);
        }else{
            graph->adjlist[source] = insertEnd(graph->adjlist[source],dest);
        }
    }else{
        if(graph->adjlist[source] == NULL){
            graph->adjlist[source] = insertBeginning(graph->adjlist[source],dest);
        }else{
            graph->adjlist[source] = insertEnd(graph->adjlist[source],dest);
        }

        if(graph->adjlist[dest] == NULL){
            graph->adjlist[dest] = insertBeginning(graph->adjlist[dest],source);
        }else{
            graph->adjlist[dest] = insertEnd(graph->adjlist[dest],source);
        }
    }
}

void printList(struct Node *head){
    if(head == NULL){
        return;
    }

    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        if(temp->next != NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }

    printf("\n");
}

void displayList(struct Graph *graph){
    for(int i = 0; i<graph->numVeritces; i++){
        printf("%d -> ", i);
        struct Node *temp = graph->adjlist[i];
        printList(temp);
    }
    printf("\n");
}

int main(){
    int v,e;
    int source,dest;
    int isDirected;
    printf("Enter No of Vertices and edges: ");
    scanf("%d %d",&v,&e);

    printf("Enter Value of directed status(0/1): ");
    scanf("%d",&isDirected);

    if(isDirected != 0 && isDirected != 1){
        printf("Invalid directed status: ");
        return -1;
    }

    struct Graph *graph = createGraph(v,isDirected);
    for(int i = 0; i<e; i++){
        printf("Enter Source and dest: ");
        scanf("%d %d",&source,&dest);
        addEdge(graph,source,dest);
    }

    displayList(graph);
    return 0;
}

