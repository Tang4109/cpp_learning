/****************************************!
*@brief  链表的删除和销毁
*@author ZhangYunjia
*@date   2019/5/12/15:37

****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef struct node
{
	int data;

	struct	node *next;//结构体套指向自己的结构体指针

}SLIST;

SLIST* create_list();//创建链表
int SLIST_print(SLIST* phead);//遍历链表
int SLIST_insert(SLIST* phead, int x, int y);//插入
int SLIST_delete(SLIST* phead, int y);//删除
int SLIST_destroy(SLIST* phead);

SLIST* create_list() {

	SLIST *phead, *pm, *pcur;
	int data;
	//创建头结点并初始化
	phead = (SLIST*)malloc(sizeof(SLIST));
	if (phead==NULL)
	{
		return NULL;
	}

	phead->data = 0;
	phead->next = NULL;
	pcur = phead;
	//提示用户输入
	printf("please enter your data:\n");
	scanf("%d", &data);

	//循环创建业务节点并初始化
	while (data!=-1)
	{
		pm = (SLIST*)malloc(sizeof(SLIST));
		if (pm == NULL)
		{
			return NULL;
		}

		pm->data = data;
		pm->next = NULL;
	
		//新节点入链表
		pcur->next = pm;
		//新节点变成当前节点
		pcur = pm;
		//提示用户输入
		printf("please enter your data:\n");
		scanf("%d", &data);
	}
	return phead;
}
int SLIST_print(SLIST* phead) {
	if (phead==NULL)
	{
		return -1;
	}
	SLIST* tmp;
	tmp = phead->next;
	printf("\nbegin print:\n");
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}

	printf("end print.\n");

	return 0;
}
int SLIST_insert(SLIST* phead, int x, int y) {
	SLIST *pM, *pcur, *ppre;
	
	//创建新的业务节点pm
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM==NULL)
	{
		return -1;
	}
	pM->next=NULL;
	pM->data = y;
	//遍历链表
	ppre = phead;
	pcur = phead->next;

	while (pcur)
	{
		if (pcur->data==x)
		{
			break;
		}
		ppre = pcur;
		pcur = pcur->next;
	}
	//新节点链接后续节点
	pM->next = ppre->next;
	//前驱节点链接新节点
	ppre->next = pM;

	return 0;
}
int SLIST_delete(SLIST* phead, int y) {
	SLIST *pcur, *ppre;
	
	//初始化
	ppre = phead;
	pcur = phead->next;

	while (pcur)
	{
		if (pcur->data==y)
		{
			break;
		}
		ppre = pcur;
		pcur = pcur->next;
	}
	if (pcur==NULL)
	{
		printf("不存在%d\n", y);
		return -1;
	}

	ppre->next = pcur->next;

	if (pcur!=NULL)
	{
		free(pcur);
	}


	return 0;
}
int SLIST_destroy(SLIST* phead) {
	SLIST* tmp = NULL;
	if (phead==NULL)
	{
		return -1;
	}
	while (phead!=NULL)
	{
		tmp = phead->next;
		free(phead);
		phead = tmp;

	}

	return 0;
}


int main()
{
	int ret = 0;
	SLIST* head = create_list();
	ret = SLIST_print(head);

	ret = SLIST_insert(head, 20, 19);
	ret = SLIST_print(head);
	
	SLIST_delete(head, 19);
	ret = SLIST_print(head);

	ret = SLIST_destroy(head);
	

	printf("end...\n");
	system("pause");
	return ret;
}