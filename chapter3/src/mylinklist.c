#include "mylinklist.h"



bool InitLinkList(List *head){

    head = (LinkList)malloc(sizeof(List));
    if(head == NULL){
        fprintf(stderr,"memory of \"head\" allocate failure!\n");
        exit(0);
    }

    head->data = 0;
    head->next = NULL;

    return true;
}

/*
    1.如果头结点为空，则return true;否则进行下一步
    2.将temp始终指向第一个结点:temp = head->next
    3.若temp != NULL,则进入循环
        4.head->next = temp->next;free(temp);
        5.temp = head->next
    6.free(head);
*/

bool ClearLinkList(List *head){

    LinkList temp;
    if(head == NULL){
        puts("the linklist is not exist!");
        return true;
    }
    
    

    temp = head->next;
    while(temp != NULL){
        head->next = temp->next;
        free(temp);
        temp = head->next;
    }

    free(head);
    return true;
}

bool LinkListEmpty(const List *head){

    if(head == NULL){
        puts("the linklist is not exist!");
        return true;
    }

    return head->data;
}

int LinkListLength(const List *head){
    return LinkListEmpty(head);
}



