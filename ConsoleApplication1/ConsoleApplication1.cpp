// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CalcFunc.h"
#include "calcStack.h"

void main()
{
	float asd = (1.2 + 2 / (float)33 - (9 * 13))*(12 * 2 * (23 * 2));
	float result = 0.f;
	result=calc_String("(1.2+2/33-(9*13))*(12*2*(23*2))");
	
	printf(" = %.3f", result);

	calc_SafeClear();
	getchar();
}