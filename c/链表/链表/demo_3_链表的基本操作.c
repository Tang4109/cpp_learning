/****************************************!
*@brief  �����ɾ��������
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

	struct	node *next;//�ṹ����ָ���Լ��Ľṹ��ָ��

}SLIST;

SLIST* create_list();//��������
int SLIST_print(SLIST* phead);//��������
int SLIST_insert(SLIST* phead, int x, int y);//����
int SLIST_delete(SLIST* phead, int y);//ɾ��
int SLIST_destroy(SLIST* phead);

SLIST* create_list() {

	SLIST *phead, *pm, *pcur;
	int data;
	//����ͷ��㲢��ʼ��
	phead = (SLIST*)malloc(sizeof(SLIST));
	if (phead==NULL)
	{
		return NULL;
	}

	phead->data = 0;
	phead->next = NULL;
	pcur = phead;
	//��ʾ�û�����
	printf("please enter your data:\n");
	scanf("%d", &data);

	//ѭ������ҵ��ڵ㲢��ʼ��
	while (data!=-1)
	{
		pm = (SLIST*)malloc(sizeof(SLIST));
		if (pm == NULL)
		{
			return NULL;
		}

		pm->data = data;
		pm->next = NULL;
	
		//�½ڵ�������
		pcur->next = pm;
		//�½ڵ��ɵ�ǰ�ڵ�
		pcur = pm;
		//��ʾ�û�����
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
	
	//�����µ�ҵ��ڵ�pm
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM==NULL)
	{
		return -1;
	}
	pM->next=NULL;
	pM->data = y;
	//��������
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
	//�½ڵ����Ӻ����ڵ�
	pM->next = ppre->next;
	//ǰ���ڵ������½ڵ�
	ppre->next = pM;

	return 0;
}
int SLIST_delete(SLIST* phead, int y) {
	SLIST *pcur, *ppre;
	
	//��ʼ��
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
		printf("������%d\n", y);
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