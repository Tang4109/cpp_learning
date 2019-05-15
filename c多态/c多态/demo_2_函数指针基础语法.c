/****************************************!
*@brief  函数指针基本语法
*@author ZhangYunjia
*@date   2019/5/15/14:05

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//函数指针基本语法

//1.定义一个函数类型

//2.定义一个函数指针类型

//3.定义一个指向函数类型的指针-数组类的指针

int add(int a, int b) {
	
	return a + b;
}

int main()
{
	add(1, 2);//直接调用,函数名就是函数的入口地址

	{
		//1.定义一个函数类型
		typedef int(func_type)(int a, int b);//定义了一个类型
		func_type* addx = NULL;//定义了一个函数指针
		addx = &add;
		int result = 0;
		result = addx(1, 2);//间接调用
		printf("%d\n", result);

	}

	{
		//2.定义一个函数指针类型
		typedef int(*func_type2)(int a, int b);//定义了一个类型
		func_type2 addx = NULL;
		addx = &add;
		int result = 0;
		result = addx(1, 2);//间接调用
		printf("%d\n", result);
	}

	{
		//3.定义一个指向函数类型的指针-数组类的指针
		int(*func_type3)(int a, int b);//定义了一个变量
		func_type3 = &add;
		int result = 0;
		result = func_type3(1, 2);//间接调用
		printf("%d\n", result);

	}

	printf("end...\n");
	system("pause");
	return 0;
}