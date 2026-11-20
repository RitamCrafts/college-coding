#include <stdio.h>

void addEdge(int v, int mat[v][v], int i, int j){
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void initGraph(int v, int mat[v][v]){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            mat[i][j] = 0;
        }
    }
}

void displayGraph(int v,  int mat[v][v]){
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main(){
    int v,e;
    printf("Enter Total No of vertices and edges: ");
    scanf("%d %d",&v,&e);
    int mat[v][v];

    initGraph(v,mat);

    int v1,v2;
    for(int i = 0; i<e; i++){
        printf("Enter 2 vertices in this edge: ");
        scanf("%d %d",&v1,&v2);
        addEdge(v,mat,v1,v2);
    }

    displayGraph(v,mat);
    return 0;
}