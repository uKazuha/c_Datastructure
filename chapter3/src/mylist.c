#include "mylist.h"




bool InitList(List *L){L->length = 0;}

bool ClearList(List *L);//用数组实现线性表的话，暂时用不上

bool ListEmpty(List L){return L.length == 0;}

int ListLength(List L){return L.length;}

bool LocateElem(List L,ElemType e){

    int pos=0;
    if(ListEmpty(L)){
        fprintf(stderr,"The List is empty!\n");
        return false;
    }
    while (pos < L.length)
    {
        if(L.data[pos++] == e) return true;
    }
    return false;

}

bool GetElem(List L,Index i,ElemType *e){

    if(i < 0 || i > L.length - 1){
        fprintf(stderr,"illegal position!\n");
        return false;
    }

    *e = L.data[i];

    return true;
}

bool ListInsert(List *L,Index i,ElemType e){

    if(L->length == MAXSIZE){
        puts("The List is full!");
        return false;
    }

    if(i < 0 || i > L->length){
        fprintf(stderr,"illegal position!\n");
        exit(0);
    }

    //如果线性表没满，位置也合法的话，开始移动元素
    //pos:指向逻辑空位，初始值为L->length
    //i:需要插入的位置下标
    //如果pos == i，则L->data[pos] = e;
    Index pos = L->length;
    while( pos > i){
        L->data[pos] = L->data[pos-1];
        pos--;
    }

    L->data[pos] = e;
    L->length += 1;

    return true;
}

bool ListDelete(List *L,Index i,ElemType *e){

    if(L->length == 0){
        puts("The List is empty!");
        return false;
    }

    if(i < 0 || i >= L->length){
        fprintf(stderr,"illegal position!\n");
        exit(0);
    }

    //如果线性表不空，位置也合法的话，开始移动元素
    //pos:指向逻辑空位（），初始值为i,假设该位置的元素被删除了
    //i:需要删除的位置下标
    //如果pos == L->length - 1，则L->length -= 1;

    Index pos = i;
    while( pos < L->length - 1){
        L->data[pos] = L->data[pos+1];
        pos++;
    }

    L->length -= 1;
    return true;
}

