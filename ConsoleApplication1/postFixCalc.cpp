// postFixCalc.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CalcFunc.h"

void main()
{
	float debug=(3+4)/(float)2-1*(5+3);


	char* str=nullptr;
	float result=calc_String("(3+4)/2-1*(5+3)");
	
	printf("(3+4)/2-1*(5+3)\n");
	printf("���� ǥ��� : %s\n",calc_getPostFixStr());
	printf("��� = %.3f",result);

	calc_SafeClear();

	getchar();

}