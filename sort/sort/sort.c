
#include"sort.h"



int StackSize(StNode* s);

void StackInit(StNode* s)
{
	assert(s);
	s->_data = (StDataType*)malloc(sizeof(StDataType) * 5);
	if (s->_data == NULL)
	{
		perror("malloc error");
		return;
	}
	s->_size = 0;
	s->_capacuty = 5;
}

void StackDestroy(StNode* s)
{
	assert(s);
	free(s->_data);
	s->_data = NULL;
	s->_size = s->_capacuty = 0;
}

void StackPush(StNode* s, StDataType x)
{
	assert(s);
	StDataType* tmp = NULL;
	if (s->_size == s->_capacuty)
	{
		s->_capacuty *= 2;
		tmp = (StDataType*)realloc(s->_data, sizeof(StDataType) * s->_capacuty);
		if (tmp == NULL)
		{
			perror("realloc error");
			return;
		}
		s->_data = tmp;
	}
	s->_data[s->_size] = x;
	s->_size++;
}

StDataType StackTop(StNode* s)
{
	assert(s);
	assert(s->_size > 0);
	return s->_data[s->_size - 1];
}

void StackPop(StNode* s)
{
	assert(s);
	assert(s->_size > 0);
	s->_size--;
}

bool StackEmpty(StNode* s)
{
	assert(s);
	if (s->_size == 0)
	{
		return true;
	}
	return false;
}

int StackSize(StNode* s)
{
	assert(s);
	return s->_size;
}

//交换
void Swap(DataType* pa, DataType* pb)
{
	DataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//打印
void Print(DataType* a, DataType n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

//直接插入排序
//时间复杂度O(N*2)
/*思路
把第一个数当成有序序列，后面的数与它进行比较
end与end+1的数进行比较，如果end+1 < end，end往后挪，直到遇到end<0或者end+1 > end时，在end+1的位置插入数值
*/
void InsertSort(DataType* a, DataType n)
{
	assert(a);
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		//将end+1的值保存
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
//1.分gap组预排序
//2.当gap==1时，进行直接插入排序
//时间复杂度O(N*1.3~N*2);
void ShellSort(DataType* a, DataType n)
{
	assert(a);
	int gap = n; 
	//当gap == 1时，进行最后一次是直接插入排序
	while (gap > 1)
	{
		//为了保证gap最后一次是1,需要+1
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[gap + end];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
//依次选出最大和最小的值，分别放到最后一个和第一个位置。
void SelectSort(DataType* a, DataType n)
{
	assert(a);
	int maxi;
	int mini;
	//闭区间
	int begin = 0;
	//!!!
	int end = n - 1;
	//注意这个区间是[begin, end]
	while (begin < end)
	{
		maxi = mini = begin;
		//注意这个区间是[begin+1, <=end]
		for (int i = begin+1; i <= end; i++)
		{
			if (a[i] > a[maxi]){
				maxi = i;
			}
			if (a[i] < a[mini]){
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//如果begin == maxi 需要更新maxi的位置
		if (begin == maxi){
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//堆排序
//向下调整算法
void AdjustDown(DataType* a, DataType root,DataType n)
{
	assert(a);

	int parent = root;
	int child = parent * 2 + 1;
	//child>n跳出循环
	while (child < n)
	{
		//child+1 防止越界访问
		if (child + 1 < n && a[child + 1] > a[child]){
			++child;
		}
		if (a[parent] < a[child]){
			Swap(&a[parent], &a[child]);
			//child>n跳出循环
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}


}
//堆排
//排升序——建大堆
//排降序——建小堆

void HeapSort(DataType* a, DataType n)
{
	assert(a);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--){	
		AdjustDown(a, i, n);
	}

	int end = n - 1;
	while (end > 0){
		//首尾交换
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		--end;
	}
}


//冒泡排序
void BubbleSort(DataType* a, DataType n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		int flag = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}

		}
		//如果比较了一趟还没有进入交换，说明前半部分已经有序
		if (flag == 0)
		{
			break;
		}
		--end;
	}

}


//优化——三数取中

int ThreeNumMid(DataType* a, int left, int right)
{
	assert(a);
	int mid = left+(right-left)/2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
		{
			return left;
		}
		else if (a[mid] < a[right])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else //a[left] < a[right]
	{
		if (a[mid] > a[right])
		{
			return right;
		}
		else if (a[mid] < a[left])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
	

}

//左右指针法
//右边做key,必须左边先走
//左边做key,必须右边先走
//左边找大，右边找小，进行交换
int Left_right_pret(DataType* a,int left,int right)
{
	assert(a);
	//注意控制区间
	int mid = ThreeNumMid(a,left, right);
	Swap(&a[mid], &a[right]);
	int begin = left;
	int end = right;
	int keyInex = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[keyInex])
		{
			++begin;
		}

		while (begin < end && a[end] >= a[keyInex])
		{
			--end;
		}
		Swap(&a[begin],&a[end]);
	}
	Swap(&a[begin], &a[keyInex]);
	return begin;
}


//挖坑法
//右边做坑，左边先走，左边做坑，右边先走
//左边找大填到坑里，更新坑的位置到左边begin值，
//右边找小填到坑里，更新坑的位置到左边end值，
int ExcavationMethod(DataType* a, int left, int right)
{
	assert(a);
	int mid = ThreeNumMid(a, left, right);
	Swap(&a[mid], &a[right]);
	int begin = left;
	int end = right;
	int hole= right;//坑

	int keyInex = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= keyInex)
		{
			++begin;
		}
		a[hole] = a[begin];
		hole = begin;

		while (begin < end && a[end] >= keyInex)
		{
			--end;
		}

		a[hole] = a[end];
		hole = end;

	}
	a[begin] = keyInex;
	hole = begin;
	return hole;
}

//前后指针法
//当cur找小时，++prev进行交换，找到大时，只++cur
int FrontBackPterMethod(DataType* a, int left, int right)
{
	assert(a);
	int mid = ThreeNumMid(a, left, right);
	Swap(&a[mid], &a[right]);
	int cur = left;
	int prev = left-1;
	int key = a[right];
	while (cur <= right)
	{
		if (a[cur] <= key&& prev!=cur )
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	return prev;
}
//快速排序
void QuickSort(DataType* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	if ((left - right) + 1 > 10)
	{
		int div = FrontBackPterMethod(a, left, right);
		//注意控制区间
		//优化二 小区间优化
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//a+left 数组起始下表
		InsertSort(a+left,right-left+1);
	}
	
}

//非递归 快速排序
void QuickSortNonR(DataType* a, int left, int right)
{
	assert(a);
	StNode s;
	StackInit(&s);
	//先入右边，在入左边
	StackPush(&s, right);
	StackPush(&s, left);

	while (!(StackEmpty(&s)))
	{
		int begin = StackTop(&s);
		StackPop(&s);
		int end = StackTop(&s);
		StackPop(&s);

		int div = FrontBackPterMethod(a, begin, end);

		//控制区间
		if (div + 1 < end-1)
		{
			StackPush(&s, end);
			StackPush(&s, div+1);
		}
		//控制区间
		if (begin + 1 < div - 1)
		{
			StackPush(&s, div-1);
			StackPush(&s, begin);
		}
		
	}
}