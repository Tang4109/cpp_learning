/****************************************!
*@brief  ¼ì²éÄÚ´æÐ¹Â©
*@author ZhangYunjia
*@date   2019/5/10/21:24

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "memwatch.h"

int get_mem(char** p_) {
	
	char* p = NULL;
	p = (char*)malloc(100);
	strcpy(p, "aaabbb");
	*p_ = p;
	return 0;
}


int main()
{
	int ret = 0;
	char* p;
	ret = get_mem(&p);
	if (ret!=0)
	{
		printf("func get_mem err: %d", ret);
		return ret;
	}
	printf("%s\n", p);
	if (p!=NULL)
	{
		free(p);
	}

	printf("end...\n");
	system("pause");
	return ret;
}