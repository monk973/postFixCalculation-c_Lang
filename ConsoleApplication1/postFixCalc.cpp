// postFixCalc.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CalcFunc.h"

void main()
{
	float debug=(3+4)/(float)2-1*(5+3);


	char* str=nullptr;
	float result=calc_String("(3+4)/2-1*(5+3)");
	
	printf("(3+4)/2-1*(5+3)\n");
	printf("후위 표기식 : %s\n",calc_getPostFixStr());
	printf("결과 = %.3f",result);

	calc_SafeClear();

	getchar();

}