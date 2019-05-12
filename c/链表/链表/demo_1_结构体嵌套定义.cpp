/****************************************!
*@brief  结构体嵌套定义（和函数体嵌套调用的区别）
*@author ZhangYunjia
*@date   2019/5/12/9:49

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Student
{
	char name[64];
	int id;
	

}Student;


typedef struct Teacher
{
	char name[64];
	int id;
	char* p;
	char** p2;

	Student s1;//结构体套结构体
	Student *s2;//结构体套结构体指针

	//结构体套自己
	//Teacher t;//err:编译器不能确定内存大小，数据类型的本质是固定大小内存块的别名

	Teacher *t;//结构体套指向自己的结构体指针

}Teacher;



int main()
{

	Teacher t1;

	
	printf("end...\n");
	system("pause");
	return 0;
}