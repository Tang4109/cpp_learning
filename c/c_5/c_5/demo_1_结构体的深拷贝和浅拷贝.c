/****************************************!
*@brief  �����ǳ����
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

//��t1������t2,�����ǳ�����������ֵĳ������ṹ������һ��ָ����߶���ָ��
void copy_teacher(Teacher* to, Teacher* from) {

	*to = *from;//��ʽ1
	//�������ʽ�ط����ڴ�
	to->name2 = (char*)malloc(100);
	strcpy(to->name2, from->name2);
	//memcpy(to,from,sizeof(Teacher))//��ʽ2
}


int main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name, "name1");
	t1.name2 = (char*)malloc(100);
	strcpy(t1.name2, "name1");

	copy_teacher(&t2, &t1);
	//�ͷ��ڴ�
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