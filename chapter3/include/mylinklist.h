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
#ifndef MYLINKLIST_H_
#define MYLINKLIST_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
typedef unsigned int Index;
/*
    线性表的链式存储结构
*/
typedef struct node{
    ElemType data;
    struct node *next;
}List,*LinkList;

bool InitLinkList(List *head);
bool ClearLinkList(List *head);
bool LinkListEmpty(const List *head);
int LinkListLength(const List *head);
bool LinkListLocateElem(List L,ElemType e);
bool LinkListGetElem(List L,Index i,ElemType *e);
bool LinkListInsert(List *L,Index i,ElemType e);
bool LinkListDelete(List *L,Index i,ElemType *e);




#endif