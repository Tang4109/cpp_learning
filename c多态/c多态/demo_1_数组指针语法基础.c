/****************************************!
*@brief  �������ͻ����﷨
*@author ZhangYunjia
*@date   2019/5/15/13:17

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//�������ͻ����﷨

//1.����һ����������

//2.����һ��ָ����������

//3.����һ��ָ���������͵�ָ��-�������ָ��



int main()
{
	//��ͳ��ʽ
	int a[10];//a�������������Ԫ�صĵ�ַ &a������������ĵ�ַ a+1��&a+1������һ����4,40��

	{
		//1.����һ����������
		typedef int(my_array)[10];
		my_array b = { 0 };
		b[0] = 10;
		printf("%d\n", b[0]);
		printf("%d\n", b[1]);

	}

	{
	 //2.����һ��ָ����������
		typedef int(*my_array2)[10];
		my_array2 c;
		c = &a;
		(*c)[0] = 20;
		printf("%d\n", a[0]);
	}
	
	{
		//3.����һ��ָ���������͵�ָ��-�������ָ��
		int(*my_array3)[10];
		my_array3 = &a;
		(*my_array3)[0] = 40;
		printf("%d\n", a[0]);
	}
	
	printf("end...\n");
	system("pause");
	return 0;
}