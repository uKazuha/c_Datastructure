#include <stdio.h>
#include "mygraph.h"

int main(void)
{
    MatrixGraph G = {
        {'A','B','C','D','E'},
        {
            {1,0,1,1,0},
            {0,1,1,1,0},
            {1,1,1,1,0},
            {1,1,1,1,0},
            {0,0,0,0,1},
        },
        5,5
    };
    DFS_Matrix_traverse(G);




    return 0;
}