#pragma once

#include "calcStack.h"



enum E_type
{
	OP=1,
	OPERAND,
	RIGHT_BRACKET
};


/*
	CORE PART
*/

//calculation for string type..
float calc_String(char* pStr);

//calculate by finished g_postfixStr
float calc_Calculate();

//
int calc_GetPriority(char ch);

//
void calc_SafeClear();


/*
	UTILITY PART
*/

//must receive as char*....     must free....
char* calc_SubStr(char* pStr, int fromIdx, int toIdx);

char* calc_getNextToken(char* pStr,int pos,int* type);

int calc_IsOP(char* pStr, int pos);
