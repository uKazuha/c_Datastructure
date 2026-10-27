#include "mysort.h"



void printArr(int arr[],int len){

    for(int i=0; i<len; i++){
        printf("%5d",arr[i]);
    }
    putchar('\n');
}

void swap(int arr[],int i,int j){

    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}


/*
    冒泡排序：两两比较,交换;例如(从小到大排序)：
        3,1,5,4,2,0,9,8,6,7
    3和1比,3大,交换位置:1,3,5,4,2,0,9,8,6,7
    3和5比,5大,不动:1,3,5,4,2,0,9,8,6,7
    5和4比,5大,交换位置:1,3,4,5,2,0,9,8,6,7
    ...
    最后9将被放到最后一个位置:1,3,4,2,0,5,8,6,7,9
    从头开始,如此每一大轮都至少有一个元素(最大)放到正确的位置

    时间复杂度：
        最好的情况是:序列已经有序:O(n)
        最差的情况是:所有元素逆序:O(n^2)
        平均O(n^2)

    空间复杂度:不需要额外辅助空间O(1)

    稳定性:未发生等值元素相对位置的移动,因此是稳定的
*/

void bubbleSort(int arr[],int len){

    int i,j;

    for(i = 0; i<len-1; i++){
        for(j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

/*
    传统的冒泡排序有一个问题：如果在某趟排序中,元素已经有序,即未发生交换位置的情况,还是会比较到底
    现对其进行改进:加一个标志即可
*/

void bubbleSortPlus(int arr[],int len){

    int i,j;
    int flag=1; //flag记录一趟排序的过程中,是否发生了数据交换,1表示发生了 

    for(i = 0; flag == 1 && i<len-1; i++){
        flag = 0;
        for(j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
                flag = 1;
            }
        }
    }
}

/*

    简单选择排序的思想是:
        假设第一个位置上的元素是最小的,将其与其他元素进行比较,并记下最小元素的下标,最后将其放在第一个位置上

    时间复杂度：
    最好的情况是:序列已经有序:O(n^2)
    最差的情况是:所有元素逆序:O(n^2)
    平均O(n^2)

    空间复杂度:不需要额外辅助空间O(1)

    稳定性:[2,2,1] → [1,2,2],因此是不稳定的（1和第一个2交换位置）

*/



void simpleSelectSort(int arr[],int len){

    int min;  //假设第一个元素最小
    int i,j;

    for(i=0; i<len; i++){
        min = i;

        for(j = i+1; j < len; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }

        if(min != i){
            swap(arr,min,i);
        }
    }
}


/*

    直接插入排序：
        假设第一个位置的元素是排好的,如果待排序的元素比前一个元素小,则往前插一个位置,然后再与它前面那个元素比较,
        一直遇到那个比他还小的元素,涉及到元素的挪动

    时间复杂度：
    最好的情况是:序列已经有序:O(n)
    最差的情况是:所有元素逆序:O(n^2)
    平均O(n^2)

    空间复杂度:不需要额外辅助空间O(1)

    稳定性:稳定的

*/


void insertSort(int arr[],int len){
    int i,j;
    int temp;
    for(i=1; i<len; i++){

        if(arr[i] < arr[i-1]){

            temp = arr[i];
            for(j = i; j > 0 && arr[j-1] > temp;j--){
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }

    }
}


/*
    希尔排序:将待排序序列按照一定的增量因子，分成若干个子序列。
            如3,1,5,4,2,0,9,8,6,7;增量因子increment设置为3，则分成以下几个子序列
            arr[0],arr[3],arr[6],arr[9]
            arr[1],arr[4],arr[7]
            arr[2],arr[5],arr[8]
            对这三个子序列实行插入排序得到三个内部子序列有序的结果,
            随后改变增量因子,将新得到的序列进行一次插入排序
            直到增量因子降到1,最后再对其进行一次插入排序

    增量因子选取非常关键,目前还是个数学难题,没有最优

    时间复杂度：


    空间复杂度:不需要额外辅助空间O(1)
    稳定性:不稳定的
*/

void shellSort(int arr[],int len){

    int increment = len;
    int i,j;
    int temp;

    do{

        increment = increment/3 + 1;

        for(i=increment; i < len; i++){

            if(arr[i] < arr[i-increment]){
                //记录需插入的元素
                temp = arr[i];

                for(j=i; j>0 && arr[j-increment] > temp; j -= increment){

                    arr[j] = arr[j-increment];
                }

                arr[j] = temp;
            }
        }


    }while(increment > 1);
    


}


/*
    堆排序：
        堆是具有如下性质的完全二叉树：
            1.每个结点的值都大于或等于其左右孩子的值：大顶堆
            2.每个结点的值都小于或等于其左右孩子的值：大顶堆

        堆排序就是利用这一性质:
            如果是大顶堆,那个序列的第一个数就是最大的数,移走它(将其与最后一个元素交换位置),然后重新调整为大顶堆
            如果是小顶堆,那个序列的第一个数就是最小的数,移走它(将其与最后一个元素交换位置),然后重新调整为大顶堆

        猜想:大顶堆用来正序排序,小顶堆用来倒序排序
        结论:如果不利用额外辅助空间,确实这样做是标准的

    堆排序的过程:
        1.调整以使其为大顶堆或小顶堆
            定位:根据完全二叉树的编号顺序我们可以知道(如果从1开始):结点为i的左孩子编号(2i),右孩子编号为2i+1
            如何调整:
                1.首次将一个完全二叉树调整为堆,需要让所有的非终端结点都变为堆的特性:从最后一个非终端结点开始,
                最后一个非终端结点的编号为 结点数/2
                2.当进行第一次移走结点时,可能破坏了堆的特性,接下来要将此时的根结点下沉,沿着较大的那个孩子结点下沉


        2.移走
*/

//将编号s...e调整为一个堆
//传入的是编号
//s是"根结点"的编号
void heapAdjust(int arr[],int s,int e){

    int temp=arr[s-1];  //记录根结点的值,因为可能被覆盖
    int j;

    /*
        
    */
    for(j=2*s; j<=e; j *= 2){   //沿着较大的那个孩子结点向下寻找

        //如果右孩子 > 左孩子
        if(j < e && arr[j] > arr[j-1])   j++;    //记录较大孩子的编号

        if(temp > arr[j-1]) break;  //如果当前的根节点已经比两个孩子大说明不用调整了

        arr[s-1] = arr[j-1];    //否则向下继续寻找,且将大的孩子提上来
        s = j;  //记录下一个可能被覆盖的根结点编号
    }

    //下沉结束
    arr[s-1] = temp;
}
//编号i(从1开始)的结点在数组位置为i-1
void heapSort(int arr[],int len){

    int i;
    //首次调整
    for(i = (len/2); i > 0; i--){
        //传入的是编号
        heapAdjust(arr,i,len);
    }

    //移走元素并调整堆
    for(i=len;i>1;i--){
        swap(arr,0,i-1);
        heapAdjust(arr,1,i-1);
    }

}





/*

    快速排序:
        通过一趟排序,使得值较小的部分都在左边,值较大的都在右边,然后返回一个中枢下标
        接这分别对这两个子序列如上所述方法进行排序,直到整个序列有序

*/

int partition(int arr[],int low,int high){

    int pivotkey = arr[low];    //我们选取第一个元素作为中间值

    while(low < high){

        //当arr[high] >= pivotkey时,说明high下标的元素不用动,high往前指
        while(low < high && arr[high] >= pivotkey) high--;
        /*
            否则说明arr[high]这个值比中间值要小,应该放在左边低位,交换low和high即可
            交换后此时low指向的就是这个比较小的值,而high指向中间值
        */
        swap(arr,low,high);

        //当arr[low] <= pivotkey时,说明low指向的元素比中间值小,则low往后指
        while(low < high && arr[low] <= pivotkey) low++;
        /*
            否则说明arr[low]这个值比中间值要大,应该放在右边高位,交换low和high即可
            交换后此时high指向的就是这个比较大的值,而low指向中间值
        */        
        swap(arr,low,high);

    }
}


void qSort(int arr[],int s,int e){

    int pivot;

    if(s < e){
        pivot = partition(arr,s,e);
        qSort(arr,s,pivot-1);
        qSort(arr,pivot+1,e);
    }
}

void quickSort(int arr[],int len){

    qSort(arr,0,len-1);

}