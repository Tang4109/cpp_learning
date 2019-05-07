/****************************************!
*@brief  读文件
*@author ZhangYunjia
*@date   2019/5/7/20:10

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main()
{

	FILE* fp = NULL;
	char *filename = "c:\\1.txt";
	char *filename2 = "C:/book/2.txt";//linux 和 windows 通用
	fp = fopen(filename2, "r+");
	if (fp == NULL) {
		printf("func fopen err:%d\n");
		return 0;
	}
	else
	{
		printf("ok.\n");
	}

	while (!feof(fp))
	{
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	printf("end...\n");
	system("pause");
	return 0;
}