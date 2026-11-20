#include <stdio.h>
#include <stdlib.h>

void initGraph(int v, int adj[v][v]){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            adj[i][j] = 0;
        }
    }
}

void addEdge(int i, int j, int v,int adj[v][v],int isDirected){


    if(isDirected != 0 && isDirected != 1) return;

    if(isDirected == 1){
        adj[i][j] = 1;
    }else {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }
}

void displayMatrix(int v, int adj[v][v]){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}


int main(){
    int v;
    printf("Enter no of vertices: ");
    scanf("%d",&v);

    int adj[v][v];

    initGraph(v,adj);
    int e;
    int source,dest;
    printf("Enter no of edges: ");
    scanf("%d",&e);

    int isDirected;

    printf("Enter Directness status(0/1): ");
    scanf("%d",&isDirected);
    for(int i = 0; i<e; i++){
        printf("Enter Source and destination: ");
        scanf("%d %d",&source,&dest);
        addEdge(source,dest,v,adj,isDirected);
    }

    printf("Adjacent matrix: \n");
    displayMatrix(v,adj);
    return 0;
}