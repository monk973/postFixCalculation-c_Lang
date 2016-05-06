#pragma once

#include "DataTypes.h"


typedef struct ST_STACK
{
	ST_DATA* stacks;
	
	int top;
	int capacity;
}calc_stack;

ST_STACK* calc_CreateStack(int _capacity);
CALC_DATATYPE calc_StackPop(ST_STACK* stack);
void calc_StackAdd(ST_STACK* stack, CALC_DATATYPE _data);
int calc_StackDeleteAll(ST_STACK** stack);
int calc_StackIsEmpty(ST_STACK* stack);
int calc_StackGetLength(ST_STACK* stack);
void calc_StackClear(ST_STACK* stack);
int calc_StackTopData(ST_STACK* stack);