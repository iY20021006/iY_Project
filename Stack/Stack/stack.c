#include"stack.h"

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

void StackPush(StNode* s,StDataType x)
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
	return s->_data[s->_size-1];
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