/*
    ADT 树(tree)
    Data
    
    Operation
        InitTree(*T)


*/


#ifndef MYTREE_H_
#define MYTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define PARENTTREESIZE 10

typedef char ElemType;

//双亲表示法：除根节点外，每个结点记录双亲的位置
typedef struct node
{
    ElemType data;
    int parent;

}ParentTreeNode;

typedef struct tree{

    ParentTreeNode tree[PARENTTREESIZE];
    int count;  //记录树中的节点数

}ParentTree;


//孩子表示法：每个结点记录自己孩子的位置，由于每个孩子的孩子数不确定，所以需要设置多个指针域==树的度，这会带来很多浪费

//孩子兄弟表示法：每个结点记录自己的第一个孩子，和它的右兄弟

/* 
    普通树暂时就到这里，接下来介绍特殊的树：二叉树

    二叉树就是度最大为2的树：即一个结点要么无孩子，要么一个孩子，要么两个孩子（左孩子和右孩子）

    二叉树的性质：
        ①设n0,n1,n2分别是度为0，度为1，度为2的节点数，则：n0 = n2 + 1
        ②深度为k的二叉树至多有：2^k - 1 个结点
        ③二叉树的第i层上至多有：2^(i-1) 个结点
        ④具有n个结点的完全二叉树，深度为 log2(n)向下取整 + 1
        ⑤如果对一棵有n个结点的完全二叉树，则如果从根节点到最后一个结点，从上到下，从左到右进行编号，从1开始，
        那么编号为i的结点，它的左孩子(如果有)编号为2i,它的右孩子(如果有)编号为2i+1

*/

/*
    二叉树的存储结构：
        1.顺序存储结构（一般而言只适合完全二叉树，这是显然的）
        2.链式存储结构
*/
typedef struct BiTreeNode{

    ElemType data;
    struct BiTree *lchild;
    struct BiTree *rchild;
}BiTreeNode,*PBiTreeNode;

typedef struct BiTree
{
    BiTreeNode *first;
    int count;

}BiTree,*PBiTree;

/*
    遍历二叉树：
        ①层序遍历:从第一层开始遍历，从上到下，从左到右
        ②前序遍历:先遍历双亲结点，再遍历左孩子，再遍历右孩子
        ③中序遍历:先遍历左孩子，再遍历双亲结点，再遍历右孩子
        ④后序遍历:先遍历左孩子，再遍历右孩子，再遍历双亲结点

    由中序遍历和前序遍历可以确定一颗二叉树，
    由中序遍历和后序遍历可以确定一颗二叉树

    二叉树用递归定义，也可以用递归遍历
*/

bool initTree(BiTree *tHead);

void preOrder(BiTreeNode *pfirst);
void inOrder(BiTreeNode *pfirst);
void postOrder(BiTreeNode *pfirst);

void preOrderCreation();

/*
    线索二叉树：在普通二叉树结点上新增了两个域ltag,rtag,它们分别记录一个结点左右指针域指向自己的孩子，还是指向自己的前驱后继

        若ltag = 0,则lchild指向左孩子;若ltag = 1,则lchild指向自己的前驱
        若rtag = 0,则rchild指向右孩子;若rtag = 1,则lchild指向自己的后继

*/

typedef struct ThreadTreeNode{

    ElemType data;
    struct BiTree *lchild;
    struct BiTree *rchild;
    bool ltag;
    bool rtag;

}ThreadTreeNode;





#endif