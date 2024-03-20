#include"sort.h"



void TestInsertSort()
{
	DataType arr[1000];
	for (int i = 0; i < 1000; i++)
	{
		arr[i] = rand()%100000+1;
	}
	int begin = clock();
	//Print(arr, sizeof(arr) / sizeof(DataType));
	InsertSort(arr, sizeof(arr) / sizeof(DataType));
	//Print(arr, sizeof(arr) / sizeof(DataType));
	
	int end = clock();
	printf("\n%d \n", end - begin);
	
}

void TestShellSort()
{
	DataType arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	Print(arr, sizeof(arr) / sizeof(DataType));
	ShellSort(arr, sizeof(arr) / sizeof(DataType));
	Print(arr, sizeof(arr) / sizeof(DataType));

}
void TestSelectSort()
{
	DataType arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	Print(arr, sizeof(arr) / sizeof(DataType));
	SelectSort(arr, sizeof(arr) / sizeof(DataType));
	Print(arr, sizeof(arr) / sizeof(DataType));
}

void TestHeapSort()
{
	DataType arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	Print(arr, sizeof(arr) / sizeof(DataType));
	BubbleSort(arr, sizeof(arr) / sizeof(DataType));
	Print(arr, sizeof(arr) / sizeof(DataType));
}

void TestQuickSort()
{
	DataType arr[100] ;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	Print(arr, sizeof(arr) / sizeof(DataType));
	//注意控制区间
	QuickSortNonR(arr, 0,sizeof(arr) / sizeof(DataType)-1);
	Print(arr, sizeof(arr) / sizeof(DataType));
}


int main()
{
	srand((unsigned)time(NULL));
	//TestShellSort();
	//TestSelectSort();
	TestQuickSort();
	
	return 0;
}