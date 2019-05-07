/****************************************!
*@brief  Æ«ÒÆÁ¿
*@author ZhangYunjia
*@date   2019/5/7/17:41

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Teacher {

	char name[64];
	int age;
	int p;
	char *name2;

}Teacher;




int main()
{
	Teacher t1;
	Teacher *p1=NULL;
	//strcpy(p1, "ddd");//err

	int offsize=(int)&(p1->age);//Æ«ÒÆÁ¿
	int offsize2 = (int)&(((Teacher*)0)->age);
	printf("%d\n", offsize);
	printf("%d\n", offsize2);
	

	printf("end...\n");
	system("pause");
	return 0;
}