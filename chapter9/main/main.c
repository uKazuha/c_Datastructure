#include "mysort.h"

int main(void)
{
    int arr[MAXSIZE] = {3,1,5,4,2,0,9,8,6,7};
    puts("Before sort:");
    printArr(arr,MAXSIZE);

    // bubbleSort(arr,MAXSIZE);
    // bubbleSortPlus(arr,MAXSIZE);
    // simpleSelectSort(arr,MAXSIZE);
    // insertSort(arr,MAXSIZE);
    // shellSort(arr,MAXSIZE);
    // heapSort(arr,MAXSIZE);
    quickSort(arr,MAXSIZE);

    puts("After sort:");
    printArr(arr,MAXSIZE);


    return 0;
}