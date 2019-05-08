/****************************************!
*@brief  按行读文件
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
	
	char *filename2 = "C:/book/2.txt";//linux 和 windows 通用
	char buf[1024];

	fp = fopen(filename2, "r+");

	if (fp == NULL) {
		printf("func fopen err:%d\n");
		return 1;
	}
	else
	{
		printf("ok.\n");
	}

	while (!feof(fp))
	{
		char *p=fgets(buf,1024,fp);//返回buf的首地址

		if (p == NULL) {
			goto End;
		}

		printf("%s", buf);
	}


End:	

	if (fp != NULL) {
		fclose(fp);
	}

	printf("end...\n");
	system("pause");
	return 0;
}