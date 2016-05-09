// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CalcFunc.h"
#include "calcStack.h"

void main()
{
	
	float debug = (1.2 + 2 / (float)33 - (9 * 13))*(12 * 2 * (23 * 2));
	float result = calc_String("(1.2+2/33-(9*13))*(12*2*(23*2))");
	

	//INSERT BREAK POINT HERE TO COMPARE RESULT AND DEBUG


	printf("(1.2+2/33-(9*13))*(12*2*(23*2))\n");
	printf("후위 표기식 : %s\n", calc_getPostFixStr());
	printf("결과 = %.3f", result);
	


	/*
	float debug = (3 + 4) / (float)2 - (1 * (5 + 3));

	float result = calc_String("(3+4)/2-(1*(5+3))");

	//INSERT BREAK POINT HERE TO COMPARE RESULT AND DEBUG

	printf("(3+4)/2-1*(5+3)\n");
	printf("후위 표기식 : %s\n", calc_getPostFixStr());
	printf("결과 = %.3f", result);
	*/
	
	calc_SafeClear();

	getchar();
}