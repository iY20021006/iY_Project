#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
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

int StackSize(StNode* s);

