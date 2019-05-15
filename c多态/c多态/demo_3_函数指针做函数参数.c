/****************************************!
*@brief  函数指针做函数参数
*@author ZhangYunjia
*@date   2019/5/15/14:31

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int add_1(int a, int b) {

	return a + b;
}

int add_2(int a, int b) {

	return a + b;
}


int add_3(int a, int b) {

	return a + b;
}


int add_4(int a, int b) {

	return a + b;
}

typedef int(*func_type)(int a, int b);

int main_op(func_type add)
{
	return add(3, 4);

}

int main_op2(int(*add_())(int a, int b))
{
	return add_(5, 6);

}

int main()
{
	//直接调用
	int result = 0;
	//result = add_(1, 2);
	//printf("%d\n", result);

	//间接调用
	func_type add = &add_1;
	result = add(1, 2);
	printf("%d\n", result);

	//函数指针做函数参数
	result = main_op(add_1);
	printf("%d\n", result);

	//函数指针做函数参数
	result = main_op(add_2);
	printf("%d\n", result);
	//函数指针做函数参数
	result = main_op(add_3);
	printf("%d\n", result);



	result = main_op2(add_1);
	printf("%d\n", result);

	printf("end...\n");
	system("pause");
	return 0;
}