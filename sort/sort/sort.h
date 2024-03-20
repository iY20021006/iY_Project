#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<assert.h>


typedef int StDataType;

typedef struct stackNode
{
	StDataType* _data;
	int _size;//记录元素个数
	int _capacuty;//容量大小
}StNode;


void StackInit(StNode* s);

void StackDestroy(StNode* s);

void StackPush(StNode* s, StDataType x);
StDataType StackTop(StNode* s);
void StackPop(StNode* s);

bool StackEmpty(StNode* s);
typedef int DataType;
//交换
void Swap(DataType* pa, DataType* pb);

//打印
void Print(DataType* a, DataType n);


//直接插入排序
void InsertSort(DataType* a, DataType n);

//希尔排序
void ShellSort(DataType* a, DataType n);

//选择排序
void SelectSort(DataType* a, DataType n);


//堆排序
void AdjustDown(DataType* a, DataType root, DataType n);
void HeapSort(DataType* a, DataType n);

//冒泡排序
void BubbleSort(DataType* a, DataType n);

//快速排序
void QuickSort(DataType* a, int left, int right);

//非递归 快速排序
void QuickSortNonR(DataType* a, int left, int right);