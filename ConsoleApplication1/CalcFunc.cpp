#include "stdafx.h"
#include "CalcFunc.h"

#define STACK_SIZE 100

calc_stack *g_calcStack = calc_CreateStack(STACK_SIZE);//연산용 저장소
calc_stack *g_opStack = calc_CreateStack(STACK_SIZE);//연산자 저장소
char* g_postfixStr = nullptr; //출력용 후위 표기식 저장소

float calc_String(char * pStr)
{
	g_postfixStr = (char*)malloc(sizeof(char)* (strlen(pStr) * 2));

	memset(g_postfixStr, 0, strlen(pStr) * 2);

	char* token = nullptr;
	int type = 0;
	int value = 0;

	int pos = 0;
	while (pStr[pos] != '\0')
	{
		token = calc_getNextToken(pStr,pos,&type);
		pos += strlen(token);


		if (type == OPERAND)
		{
			strcat(g_postfixStr, token);
			strcat(g_postfixStr, " ");
		}
		else if (type == RIGHT_BRACKET)
		{
			while (!calc_StackIsEmpty(g_opStack))
			{
				value = calc_StackPop(g_opStack);

				if (value == '(')
				{
					break;
				}
				else
				{
					strcat(g_postfixStr, (char*)(&value));
					strcat(g_postfixStr, " ");
				}

			}
		}
		else if (type == OP)
		{
			if (!calc_StackIsEmpty(g_opStack) &&
				calc_GetPriority(calc_StackTopData(g_opStack)) > calc_GetPriority(token[0]))
			{
				while (!calc_StackIsEmpty(g_opStack) &&
					calc_StackTopData(g_opStack) != '(')
				{
					value = calc_StackPop(g_opStack);

					strcat(g_postfixStr, (char*)(&value));
					strcat(g_postfixStr, " ");
				}

			}
			calc_StackAdd(g_opStack, token[0]);
		}


		//because of calc_SubStr Func...  this func assign new memory...   
		free(token);

		token = nullptr;
		value = 0;
	}//END WHILE

	while (!calc_StackIsEmpty(g_opStack))
	{
		value = calc_StackPop(g_opStack);
		strcat(g_postfixStr, (char*)(&value));
	}

	/*
	//debug
	int i = 0;
	while (g_postfixStr[i] != '\0')
	{
		printf("%c",g_postfixStr[i++]);
	}
	*/

	return calc_Calculate();
}

float calc_Calculate()
{
	int pos = 0;
	int toIdx = 0;

	float operand1 = 0.f, operand2 = 0.f;
	
	char* tmpStr = 0;
	char op = 0;

	while (g_postfixStr[pos] != '\0')
	{
		if (calc_IsOP(g_postfixStr, pos))
		{
			operand1 = calc_StackPop(g_calcStack);
			operand2 = calc_StackPop(g_calcStack);

			op = g_postfixStr[pos];
			float tmpResult;
			switch (op)
			{
			case '+':
				tmpResult = operand2 + operand1  ;
				calc_StackAdd(g_calcStack, tmpResult);
				break;
			case '-':
				tmpResult = operand2 - operand1  ;
				calc_StackAdd(g_calcStack, tmpResult);
				break;
			case '*':
				tmpResult = operand2 * operand1  ;
				calc_StackAdd(g_calcStack, tmpResult);
				break;
			case '/':
				tmpResult = operand2 / operand1;
				calc_StackAdd(g_calcStack, tmpResult);
				break;
			}

			pos+=2;
		}
		else {
			while (g_postfixStr[++toIdx] != ' ');

			tmpStr = calc_SubStr(g_postfixStr, pos, toIdx-1);

			calc_StackAdd(g_calcStack, atof(tmpStr));

			pos += strlen(tmpStr) + 1;
			char a = g_postfixStr[pos];
			free(tmpStr);
		}


		
		toIdx = pos;
	}

	float result= calc_StackPop(g_calcStack);

	return result;
}

char* calc_getPostFixStr()
{
	return g_postfixStr;
}

int calc_GetPriority(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 0;

	case '*':
	case '/':
		return 1;


	case '(':
		return 2;

	}

}

void calc_SafeClear()
{

	free(g_postfixStr);
	calc_StackDeleteAll(&g_calcStack);
	calc_StackDeleteAll(&g_opStack);
	g_postfixStr = nullptr;
}


char * calc_SubStr(char * pStr, int fromIdx, int toIdx)
{
	if (fromIdx > toIdx)
		return nullptr;


	int len = toIdx - fromIdx+1;

	char* tmpStr = (char*)malloc(((sizeof(char)* len) + 1));

	for (int i = 0; i < len; ++i)
	{
		tmpStr[i] = pStr[fromIdx + i];
	}

	tmpStr[len] = '\0';


	return tmpStr;
}

char * calc_getNextToken(char * pStr,int pos,int* type)
{
	int toIdx = pos; 

	if (calc_IsOP(pStr, pos))
	{
		*type = pStr[pos] == ')' ? RIGHT_BRACKET : OP;
		return calc_SubStr(pStr, pos, toIdx);
	}

	*type = OPERAND;

	while (!calc_IsOP(pStr, toIdx))
		toIdx++;

	return calc_SubStr(pStr, pos, toIdx-1);
}

int calc_IsOP(char * pStr,int pos)
{
	static char op[] = { '+','-','*','/','(',')' };

	for (int i = 0; i < op[i] != '\0'; ++i)
	{
		if (op[i] == pStr[pos])
		{
			return 1;
		}
	}

	return 0;
}
