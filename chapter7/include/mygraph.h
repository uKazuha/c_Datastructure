/*

    一些关于图的术语:
        1.顶点、边、弧
        2.简单图,完全图,无向图,有向图
        3.连通图,强连通图
        4.连通分量,强连通分量
        5.子图
        6.路径、简单回路
        7.权,网
        8.最小生成树
        

*/





#ifndef MYGRAPH_H_
#define MYGRAPH_H_

#define MAXSIZE 5

typedef char VerxType;
typedef int EdgeType;

/*
    图的存储结构:
        1.邻接矩阵法
        2.邻接表法
        3.十字链表法
        4.邻接多重表
*/

/*
    1.邻接矩阵法:一个一维数组记录顶点信息,一个二维数组记录边(或弧)的信息;无向图和有向图都能用
        -若要判断两个顶点之间有没有边,查看edge[i][j]的信息即可,时间复杂度O(1);
        -若要计算顶点的度,则遍历该行或该列即可,时间复杂度O(n);
        -适用于边稠密图
*/

typedef struct MGraph{

    VerxType vertex[MAXSIZE];   //记录顶点信息
    EdgeType edge[MAXSIZE][MAXSIZE];    //记录边的信息
    int verxNum;    //记录顶点数量
    int edgeNum;    //记录边的数量

}MatrixGraph;

/*
    2.邻接表法:用一个一维数组记录顶点信息,这个顶点结构包含指向第一条边结构的指针;
            然后边结构除了记录相关的信息,还包括指向下一条边结构的指针;
        -若想判断某顶点和另一个顶点之间是否存在边,遍历该顶点的边集链表即可,时间复杂度O(n);
        -若想计算某无向图顶点的度,遍历该顶点的边集链表即可,时间复杂度为O(n);

    邻接表对于有向图而言,想要直到顶点的出度直接遍历该顶点的边集链表即可,但是获取入度就要遍历整个图
    逆邻接表则相反,因为这是存储结构在记录边的信息时决定的特性。这对于有向图来说还是不太友好
*/

//2.1 边结构
typedef struct AdjEdge{

    int adjvex; //存储邻接顶点的下标
    EdgeType edge;
    struct AdjEdge* next;

}AdjEdge;

//2.2 顶点结构
typedef struct AdjVerx{
    VerxType data;
    struct AdjEdge* first;
}AdjVerx;

//2.3 邻接表结构
typedef struct AdjGraph{

    AdjVerx vertex[MAXSIZE];
    int verxNum;
    int edgeNum;

}AdjGraph;

/*
    3.十字链表法: 对于有向图的邻接表的优化存储结构

            将邻接表和逆邻接表的特性结合起来。重新定义顶点结点结构:即数据域和两个指针域,一个指向第一条出边,一个指向第一条
            入边。而边结点则记录:弧起点的下标,弧终点的下标,下一条起点相同的边结点,下一条终点相同的边结点

        -适用于有向图
        -求某顶点的出度:沿着firstout指针遍历边结点,在每个边结点沿着下一条起点相同的方向遍历,直到结尾;O(n)
        -求某顶点的入度:沿着firstin指针遍历边结点,在每个边结点沿着下一条终点相同的方向遍历,直到结尾;O(n)
        -判断Vi 到 Vj是否有弧:沿着firstout指针遍历边结点,在每个边结点沿着下一条起点相同的方向遍历,直到找到某边结点
         endVerx域等于Vj;O(n)
*/
//3.1 边结点结构
typedef struct OrthEdge{

    int startVerx;  //弧起点的下标
    int endVerx;    //弧终点的下标

    struct OrthEdge* sameStartEdge; //下一条起点相同的边
    struct OrthEdge* sameEndEdge;   //下一条终点相同的边

}OrthEdge;

//3.2 顶点结点结构
typedef struct OrthVerx{

    VerxType verx;
    struct OrthEdge* firstin;
    struct OrthEdge* firstout;

}OrthVerx;

//3.3 十字链表结构
typedef struct OrthGraph{

    OrthVerx vertex[MAXSIZE];
    int verxNum;
    int edgeNum;

}OrthGraph;

/*
    4.邻接多重表:对无向图邻接表优化的存储结构

            重新定义顶点结点的信息:数据域、第一条边的指针;
            重新定义边结点的信息:该边依附顶点Vi的下标、下一条依附顶点Vi的边;该边依附顶点Vj的下标、下一条依附顶点Vj的边

*/
//4.1 边结点结构
typedef struct MultiEdge{

    int iVerx;
    struct MultiEdge* iLink;

    int jVerx;
    struct MultiEdge* jLink;

}MultiEdge;

//4.2 顶点结点结构
typedef struct MultiVerx{

    VerxType verx;
    struct MultiEdge* first;

}MultiVerx;

//4.3 邻接多重表结构
typedef struct MultiGraph{

    struct MultiVerx vertex[MAXSIZE];
    int verxNum;
    int edgeNum;

}MultiGraph;



#endif