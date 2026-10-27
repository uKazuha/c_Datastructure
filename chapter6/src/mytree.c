#include "mytree.h"


bool initTree(BiTree *tHead){

    tHead = (BiTree *)malloc(sizeof(BiTree));
    if (tHead)
    {
        tHead->first = NULL;
        tHead->count = 0;
        return true;
    }
    
    puts("Initial Failure!");
    return false;
}

void preOrder(BiTreeNode *pfirst){

    if(pfirst != NULL){
        putchar(pfirst->data);
        preOrder(pfirst->lchild);
        preOrder(pfirst->rchild);
    }

}

void inOrder(BiTreeNode *pfirst){

    if(pfirst != NULL){
        preOrder(pfirst->lchild);
        putchar(pfirst->data);
        preOrder(pfirst->rchild);
    }

}

void postOrder(BiTreeNode *pfirst){

    if(pfirst != NULL){
        preOrder(pfirst->lchild);
        preOrder(pfirst->rchild);
        putchar(pfirst->data);
    }

}

