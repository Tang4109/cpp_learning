/****************************************!
*@brief  �ṹ��Ƕ�׶��壨�ͺ�����Ƕ�׵��õ�����
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

	Student s1;//�ṹ���׽ṹ��
	Student *s2;//�ṹ���׽ṹ��ָ��

	//�ṹ�����Լ�
	//Teacher t;//err:����������ȷ���ڴ��С���������͵ı����ǹ̶���С�ڴ��ı���

	Teacher *t;//�ṹ����ָ���Լ��Ľṹ��ָ��

}Teacher;



int main()
{

	Teacher t1;

	
	printf("end...\n");
	system("pause");
	return 0;
}