#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct Queue{
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void init(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue *q){
    return q->front == -1;
}

bool isFull(struct Queue *q){
    return q->rear == MAX_SIZE-1;
}

void enQueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue full.\n");
        return;
    }

    if(q->front == -1){
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = val;
}

int deQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return -1;
    }

    int poppedElement = q->arr[q->front];

    if(q->front == q->rear){
        init(q);
    }
    else{
        q->front++;
    }

    return poppedElement;
}

void initGraph(int v, int adj[v][v]){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            adj[i][j] = 0;
        }
    }
}

void addEdge(int v, int adj[v][v],int i, int j, int isDirected){
    if(isDirected != 0 && isDirected != 1) return;
    if(isDirected == 1){
        adj[i][j] = 1;
    }else{
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
}

void bfs(int start, int v, int adj[v][v]){
    struct Queue *q = malloc(sizeof(struct Queue));
    init(q);
    int visited[v];
    for(int i = 0; i<v; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    enQueue(q,start);

    while(!isEmpty(q)){
        int curr = deQueue(q);
        printf("%d ",curr);
        for(int i = 0; i<v; i++){
            if(adj[curr][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                enQueue(q,i);
            }
        }
    }

    free(q);
}

int main(){
    int v,e;
    int source,dest;
    int isDirected;
    printf("Enter Total no of vertices and edges: ");
    scanf("%d %d",&v,&e);
    int adj[v][v];
    initGraph(v,adj);

    printf("Enter Directness status: ");
    scanf("%d",&isDirected);
    for(int i = 0; i<e; i++){
        printf("Enter Source and dest: ");
        scanf("%d %d",&source,&dest);
        addEdge(v,adj,source,dest,isDirected);
    }

    int start;
    printf("Enter Start Vertex: ");
    scanf("%d",&start);
    printf("BFS: \n");
    bfs(start,v,adj);
    printf("\n");
    return 0;
}