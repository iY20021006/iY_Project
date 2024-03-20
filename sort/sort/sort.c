
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

//����
void Swap(DataType* pa, DataType* pb)
{
	DataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//��ӡ
void Print(DataType* a, DataType n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
//ʱ�临�Ӷ�O(N*2)
/*˼·
�ѵ�һ���������������У���������������бȽ�
end��end+1�������бȽϣ����end+1 < end��end����Ų��ֱ������end<0����end+1 > endʱ����end+1��λ�ò�����ֵ
*/
void InsertSort(DataType* a, DataType n)
{
	assert(a);
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		//��end+1��ֵ����
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

//ϣ������
//1.��gap��Ԥ����
//2.��gap==1ʱ������ֱ�Ӳ�������
//ʱ�临�Ӷ�O(N*1.3~N*2);
void ShellSort(DataType* a, DataType n)
{
	assert(a);
	int gap = n; 
	//��gap == 1ʱ���������һ����ֱ�Ӳ�������
	while (gap > 1)
	{
		//Ϊ�˱�֤gap���һ����1,��Ҫ+1
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

//ѡ������
//����ѡ��������С��ֵ���ֱ�ŵ����һ���͵�һ��λ�á�
void SelectSort(DataType* a, DataType n)
{
	assert(a);
	int maxi;
	int mini;
	//������
	int begin = 0;
	//!!!
	int end = n - 1;
	//ע�����������[begin, end]
	while (begin < end)
	{
		maxi = mini = begin;
		//ע�����������[begin+1, <=end]
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
		//���begin == maxi ��Ҫ����maxi��λ��
		if (begin == maxi){
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//������
//���µ����㷨
void AdjustDown(DataType* a, DataType root,DataType n)
{
	assert(a);

	int parent = root;
	int child = parent * 2 + 1;
	//child>n����ѭ��
	while (child < n)
	{
		//child+1 ��ֹԽ�����
		if (child + 1 < n && a[child + 1] > a[child]){
			++child;
		}
		if (a[parent] < a[child]){
			Swap(&a[parent], &a[child]);
			//child>n����ѭ��
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}


}
//����
//�����򡪡������
//�Ž��򡪡���С��

void HeapSort(DataType* a, DataType n)
{
	assert(a);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--){	
		AdjustDown(a, i, n);
	}

	int end = n - 1;
	while (end > 0){
		//��β����
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		--end;
	}
}


//ð������
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
		//����Ƚ���һ�˻�û�н��뽻����˵��ǰ�벿���Ѿ�����
		if (flag == 0)
		{
			break;
		}
		--end;
	}

}


//�Ż���������ȡ��

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

//����ָ�뷨
//�ұ���key,�����������
//�����key,�����ұ�����
//����Ҵ��ұ���С�����н���
int Left_right_pret(DataType* a,int left,int right)
{
	assert(a);
	//ע���������
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


//�ڿӷ�
//�ұ����ӣ�������ߣ�������ӣ��ұ�����
//����Ҵ��������¿ӵ�λ�õ����beginֵ��
//�ұ���С�������¿ӵ�λ�õ����endֵ��
int ExcavationMethod(DataType* a, int left, int right)
{
	assert(a);
	int mid = ThreeNumMid(a, left, right);
	Swap(&a[mid], &a[right]);
	int begin = left;
	int end = right;
	int hole= right;//��

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

//ǰ��ָ�뷨
//��cur��Сʱ��++prev���н������ҵ���ʱ��ֻ++cur
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
//��������
void QuickSort(DataType* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	if ((left - right) + 1 > 10)
	{
		int div = FrontBackPterMethod(a, left, right);
		//ע���������
		//�Ż��� С�����Ż�
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		//a+left ������ʼ�±�
		InsertSort(a+left,right-left+1);
	}
	
}

//�ǵݹ� ��������
void QuickSortNonR(DataType* a, int left, int right)
{
	assert(a);
	StNode s;
	StackInit(&s);
	//�����ұߣ��������
	StackPush(&s, right);
	StackPush(&s, left);

	while (!(StackEmpty(&s)))
	{
		int begin = StackTop(&s);
		StackPop(&s);
		int end = StackTop(&s);
		StackPop(&s);

		int div = FrontBackPterMethod(a, begin, end);

		//��������
		if (div + 1 < end-1)
		{
			StackPush(&s, end);
			StackPush(&s, div+1);
		}
		//��������
		if (begin + 1 < div - 1)
		{
			StackPush(&s, div-1);
			StackPush(&s, begin);
		}
		
	}
}