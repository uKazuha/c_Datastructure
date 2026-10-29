#include "mygraph.h"




void DFS_Matrix(MatrixGraph G,int i,bool visited[]){

    int j;

    visited[i] = true;
    printf("%c\n",G.vertex[i]);

    for(j=0; j<G.verxNum; j++){

        if(G.edge[i][j] == 1 && !visited[j]){
            DFS_Matrix(G,j,visited);
        }

    }


}


void DFS_Matrix_traverse(MatrixGraph G){

    int i;
    bool visited[MAXSIZE] = {false,false,false,false,false};

    for(i=0; i<G.verxNum; i++){
        if(!visited[i]) DFS_Matrix(G,i,visited);
    }
}



void BFS_Matrix_traverse(MatrixGraph G){

    int queue[MAXSIZE];

}