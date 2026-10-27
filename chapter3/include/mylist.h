/*
    ADT 线性表（list）

    Data

    Operation:
        InitList(List *L);
        ClearList(List *L);
        ListEmpty(List L);
        ListLength(List L);
        LocateElem(List L,ElemType e);
        GetElem(List L,Index i,Elemtype *e);
        ListInsert(List *L,Index i,ElemType e);
        ListDelete(List *L,Index i,ElemType *e);

    endADT

*/
#ifndef MYLIST_H_
#define MYLIST_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElemType;
typedef unsigned int Index;
/*
    线性表的顺序存储结构
*/
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}List;

bool InitList(List *L);
bool ClearList(List *L);
bool ListEmpty(List L);
int ListLength(List L);
bool LocateElem(List L,ElemType e);
bool GetElem(List L,Index i,ElemType *e);
bool ListInsert(List *L,Index i,ElemType e);
bool ListDelete(List *L,Index i,ElemType *e);




#endif