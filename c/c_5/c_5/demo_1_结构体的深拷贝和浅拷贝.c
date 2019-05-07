/****************************************!
*@brief  深拷贝与浅拷贝
*@author ZhangYunjia
*@date   2019/5/7/16:43

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Teacher {

	char name[64];
	int age;
	char *name2;

}Teacher;

//将t1拷贝给t2,深拷贝与浅拷贝经常出现的场景：结构体中有一级指针或者二级指针
void copy_teacher(Teacher* to, Teacher* from) {

	*to = *from;//方式1
	//深拷贝：显式地分配内存
	to->name2 = (char*)malloc(100);
	strcpy(to->name2, from->name2);
	//memcpy(to,from,sizeof(Teacher))//方式2
}


int main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name, "name1");
	t1.name2 = (char*)malloc(100);
	strcpy(t1.name2, "name1");

	copy_teacher(&t2, &t1);
	//释放内存
	if (t1.name2!=NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}

	if (t2.name2 != NULL)
	{
		free(t2.name2);//
		t2.name2 = NULL;
	}

	
	printf("end...\n");
	system("pause");
	return 0;
}