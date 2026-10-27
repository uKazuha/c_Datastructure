#ifndef MYSORT_H_
#define MYSORT_H_

#include <stdio.h>

#define MAXSIZE 10

void printArr(int arr[],int len);
void swap(int arr[],int i,int j);

void bubbleSort(int arr[],int len);
void bubbleSortPlus(int arr[],int len);

void simpleSelectSort(int arr[],int len);

void insertSort(int arr[],int len);

void shellSort(int arr[],int len);

void heapAdjust(int arr[],int s,int e);
void heapSort(int arr[],int len);


int partition(int arr[],int low,int high);
void qSort(int arr[],int s,int e);
void quickSort(int arr[],int len);

#endif