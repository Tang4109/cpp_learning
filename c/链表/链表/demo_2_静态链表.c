/****************************************!
*@brief  静态链表的内存生命周期问题
*@author ZhangYunjia
*@date   2019/5/12/10:16

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef struct Teacher
{
	int data;

	struct	Teacher *next;//结构体套指向自己的结构体指针

}Teacher;

Teacher* create_list() {
	//静态链表
	Teacher t1, t2, t3;
	Teacher* p;

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;

	t1.next = &t2;
	t2.next = &t3;
	t3.next = NULL;

	p = &t1;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;//指针的下移
	}


	return &t1;
}


int main()
{

	Teacher* head = create_list();
	printf("%d\n",head->data);
	printf("%d\n", head->next->data);//静态链表存在节点的内存生命周期问题

	
	printf("end...\n");
	system("pause");
	return 0;
}