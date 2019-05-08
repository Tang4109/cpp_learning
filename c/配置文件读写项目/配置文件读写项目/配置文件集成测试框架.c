/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/8/13:50

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define CFGNAME "c:/book/mycfg.ini"


//��ʾ�˵�
void menu() {
	printf("=================================\n");
	printf("1 ����д�����ļ�\n");
	printf("2 ���Զ������ļ�\n");
	printf("0 �˳�\n");
	printf("=================================\n");
}

//��������
int test_GetCfg() {

	int ret = 0;
	int value_len = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	printf("\n�����key: ");
	scanf("%s", name);

	ret = GetCfgItem(CFGNAME, name,value, &value_len);
	
	if (ret != 0) {
		printf("func GetCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("value:%s\n", value);
	return ret;
}
//д������
//ѭ����ÿһ�У����keyֵ�Ƿ���ڣ����������޸Ķ�Ӧ��valueֵ
//�������ڣ����ļ�ĩβ���������
int test_WriteCfg() {
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	printf("\n�����key: ");
	scanf("%s", name);

	printf("\n�����value: ");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME, name, value, strlen(value));
	if (ret != 0) {
		printf("func WriteCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("�������ʱ��%s=%s\n", name, value);
	return ret;
}

int main()
{
	int choice;

	for (;;) {
		//���ѡ��
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://д������
			test_WriteCfg();
			break;
		case 2://��������
			test_GetCfg();
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}

	}
	
	printf("end...\n");
	system("pause");
	return 0;
}