/****************************************!
*@brief  ʹ�� n ��ָ���β��޸� n-1��ָ��ʵ�ε�ֵ
*@author ZhangYunjia
*@date   2019/5/10/9:33

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void use_pointer(int** p) {
	*p = 10;
}


int main()
{

	
	int** p = NULL;
	p = 1;
	printf("%d\n", p);

	use_pointer(&p);
	printf("%d\n", p);

	printf("end...\n");
	system("pause");
	return 0;
}