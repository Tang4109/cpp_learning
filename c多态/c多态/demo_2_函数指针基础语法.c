/****************************************!
*@brief  ����ָ������﷨
*@author ZhangYunjia
*@date   2019/5/15/14:05

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//����ָ������﷨

//1.����һ����������

//2.����һ������ָ������

//3.����һ��ָ�������͵�ָ��-�������ָ��

int add(int a, int b) {
	
	return a + b;
}

int main()
{
	add(1, 2);//ֱ�ӵ���,���������Ǻ�������ڵ�ַ

	{
		//1.����һ����������
		typedef int(func_type)(int a, int b);//������һ������
		func_type* addx = NULL;//������һ������ָ��
		addx = &add;
		int result = 0;
		result = addx(1, 2);//��ӵ���
		printf("%d\n", result);

	}

	{
		//2.����һ������ָ������
		typedef int(*func_type2)(int a, int b);//������һ������
		func_type2 addx = NULL;
		addx = &add;
		int result = 0;
		result = addx(1, 2);//��ӵ���
		printf("%d\n", result);
	}

	{
		//3.����һ��ָ�������͵�ָ��-�������ָ��
		int(*func_type3)(int a, int b);//������һ������
		func_type3 = &add;
		int result = 0;
		result = func_type3(1, 2);//��ӵ���
		printf("%d\n", result);

	}

	printf("end...\n");
	system("pause");
	return 0;
}