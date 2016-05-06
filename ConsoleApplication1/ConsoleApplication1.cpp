// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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