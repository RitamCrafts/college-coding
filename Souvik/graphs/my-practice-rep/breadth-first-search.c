#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

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

struct Graph *creategraph(int v,int isDirected){
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

int main(){
    
    return 0;
}