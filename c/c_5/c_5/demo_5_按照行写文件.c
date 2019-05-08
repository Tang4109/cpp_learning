/****************************************!
*@brief  按行读写文件
*@author ZhangYunjia
*@date   2019/5/7/20:42

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main()
{

	FILE* fp = NULL;
	char *filename = "c:\\book\\3.txt";
	char *filename2 = "C:/book/2.txt";//linux 和 windows 通用
	char a[27] = "abcde";

	fp = fopen(filename, "w+");
	if (fp == NULL) {
		printf("func fopen err:%d\n");
		return 0;
	}
	else
	{
		printf("ok.\n");
	}

	fputs(a, fp);

	if (fp != NULL) {
		fclose(fp);
	}

	printf("end...\n");
	system("pause");
	return 0;
}