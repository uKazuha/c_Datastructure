#include <stdio.h>
#include "mylist.h"

void printarr(const int *arr,int size);

int main(void)
{
    
    List L;
    InitList(&L);

    int n;
    Index i=0;
    printf("Please input some integers(No more than 10 numbers):\n");

    while(scanf("%d",&n) == 1 && i < MAXSIZE){
        ListInsert(&L,i,n);
        i++;
    }

    puts("here are the primary array:");
    printarr(L.data,L.length);

    //插入一个元素
    ListInsert(&L,2,0);
    printarr(L.data,L.length);

    //删除一个元素
    ListDelete(&L,2,&n);
    printarr(L.data,L.length);


    return 0;
}



void printarr(const int *arr,int size){

    for(int i = 0; i < size; i++){

        printf("%5d",arr[i]);

    }

    putchar('\n');
}