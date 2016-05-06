#include "stdafx.h"
#include "calcStack.h"


#define EXT_LEN 2


ST_STACK* calc_CreateStack(int _capacity)
{
	ST_STACK *tmpStack;
	tmpStack = (ST_STACK*)malloc(sizeof(ST_STACK));
	tmpStack->stacks = (ST_DATA*)malloc(sizeof(ST_DATA)*_capacity);
	tmpStack->top = 0;
	tmpStack->capacity = _capacity;

	//init datas...
	for (int i = 0; i < _capacity; ++i)
	{
		tmpStack->stacks[i].data = 0;
	}

	return tmpStack;
}

void calc_StackAdd(ST_STACK* stack, CALC_DATATYPE _data)
{

	if (stack->top < stack->capacity)
	{
		stack->stacks[stack->top].data = _data;
		
	}
	else
	{
		stack->stacks = (ST_DATA*)realloc(stack->stacks, sizeof(ST_DATA)* (stack->capacity * EXT_LEN));

		stack->stacks[stack->top].data = _data;

		stack->capacity *= EXT_LEN;

		//init datas...
		for (int i = stack->top + 1; i < stack->capacity; ++i)
		{
			stack->stacks[i].data = 0;
		}

	}

	(stack->top)++;
}
CALC_DATATYPE calc_StackPop(ST_STACK* stack)
{
	float ret = -1;//error value

	/*
		Stack State

		3 idx : no data yet...   <<<<<===== top pointing...
		2 idx : some value3  
		1 idx : some value2
		0 idx : some value1
			
	*/

	if (stack->top > 0)
	{
		stack->top--;
		ret = stack->stacks[stack->top].data;
		stack->stacks[stack->top].data = 0;
	}

	return ret;
}


int calc_StackDeleteAll(ST_STACK** stack)
{
	if(*stack){
		free((*stack)->stacks);
		free(*stack);
		*stack = nullptr;

		return 1;
	}
	else
	{
		return -1; //(*stack) is null.. error
	}

}

int calc_StackIsEmpty(ST_STACK* stack)
{
	return stack->top == 0;
}

int calc_StackGetLength(ST_STACK* stack)
{
	return stack->top;
}

void calc_StackClear(ST_STACK* stack)
{
	for (int i = 0; i < stack->top; ++i)
	{
		stack->stacks[i].data = 0;
	}
	stack->top = 0;

}

int calc_StackTopData(ST_STACK * stack)
{
	return stack->stacks[stack->top-1].data;
}
