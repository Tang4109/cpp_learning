/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/9/15:10

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int get_content_and_len(const char* file_name,char** buf, int *len) {
	char* tmp = NULL;
	tmp = (char*)malloc(100 * sizeof(char));
	if (tmp==NULL)
	{
		return -1;
	}
	strcpy(tmp, "zyj");
	*buf = tmp;
	*len = 10;

	return 0;
}

int get_content_and_len2(const char* file_name, char** buf, int *len) {
	
	if (buf == NULL)
	{
		*len = 10;
	}
	else
	{
		*len = 10;
		strncpy(buf, "zyjzyjzyjzyjzyzyzyzyzyyz", *len);
		
	}
	
	return 0;
}

int main()
{
	const char* file_name = "c:/2.txt";
	char* p = NULL;
	int len = 0;
	//get_content_and_len(file_name, &p, &len);
	//printf("%s\n", p);
	//if (p!=NULL)
	//{
	//	free(p);
	//	p = NULL;
	//}

	get_content_and_len2(file_name, NULL, &len);
	p = (char*)malloc(len);
	if (p==NULL)
	{
		return -1;
	}
	get_content_and_len2(file_name, p, &len);
	printf("%s\n", p);
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}



	printf("end...\n");
	system("pause");
	return 0;
}