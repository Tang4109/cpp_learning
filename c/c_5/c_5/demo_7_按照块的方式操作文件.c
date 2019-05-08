/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/8/9:54

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Teacher
{
	char name[64];
	int age;

}Teacher;//名字可以一样

void file_write() {
	
	int count=0;
	FILE *fp = NULL;
	char *filename = "c:/book/1.dat";

	Teacher t_array[3];

	for (int i=0;i<3;i++)
	{
		sprintf(t_array[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		t_array[i].age = i + 31;
	}

	fp = fopen(filename, "w+b");

	if (fp=NULL)
	{
		printf("func fopen err\n");
		return;
	}

	for (int i=0;i<3;i++)
	{
		count=fwrite(&t_array[i], sizeof(Teacher), 1, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
	}

	return;
}

int main()
{

	file_write();
	
	printf("end...\n");
	system("pause");
	return 0;
}