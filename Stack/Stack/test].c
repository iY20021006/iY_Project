#include"stack.h"

void TestStack()
{
	StNode s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	int size = StackSize(&s);
	printf("%d ",size);
	while (!StackEmpty(&s))
	{
		StDataType tmp = StackTop(&s);
		StackPop(&s);
		printf("%d ",tmp);
	}

	StackDestroy(&s);
}

int main()
{
	TestStack();
	return 0;
}