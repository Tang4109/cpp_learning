/****************************************!
*@brief  数组类型基本语法
*@author ZhangYunjia
*@date   2019/5/15/13:17

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//数组类型基本语法

//1.定义一个数组类型

//2.定义一个指针数组类型

//3.定义一个指向数组类型的指针-数组类的指针



int main()
{
	//传统方式
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 a+1和&a+1步长不一样（4,40）

	{
		//1.定义一个数组类型
		typedef int(my_array)[10];
		my_array b = { 0 };
		b[0] = 10;
		printf("%d\n", b[0]);
		printf("%d\n", b[1]);

	}

	{
	 //2.定义一个指针数组类型
		typedef int(*my_array2)[10];
		my_array2 c;
		c = &a;
		(*c)[0] = 20;
		printf("%d\n", a[0]);
	}
	
	{
		//3.定义一个指向数组类型的指针-数组类的指针
		int(*my_array3)[10];
		my_array3 = &a;
		(*my_array3)[0] = 40;
		printf("%d\n", a[0]);
	}
	
	printf("end...\n");
	system("pause");
	return 0;
}