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
	int _size;//��¼Ԫ�ظ���
	int _capacuty;//������С
}StNode;


void StackInit(StNode* s);

void StackDestroy(StNode* s);

void StackPush(StNode* s, StDataType x);
StDataType StackTop(StNode* s);
void StackPop(StNode* s);

bool StackEmpty(StNode* s);
typedef int DataType;
//����
void Swap(DataType* pa, DataType* pb);

//��ӡ
void Print(DataType* a, DataType n);


//ֱ�Ӳ�������
void InsertSort(DataType* a, DataType n);

//ϣ������
void ShellSort(DataType* a, DataType n);

//ѡ������
void SelectSort(DataType* a, DataType n);


//������
void AdjustDown(DataType* a, DataType root, DataType n);
void HeapSort(DataType* a, DataType n);

//ð������
void BubbleSort(DataType* a, DataType n);

//��������
void QuickSort(DataType* a, int left, int right);

//�ǵݹ� ��������
void QuickSortNonR(DataType* a, int left, int right);