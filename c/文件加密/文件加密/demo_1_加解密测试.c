/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/9/9:02

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "des.h"

int main()
{
	int ret = 0;
	char *plain = "123456789";
	int plain_len = strlen(plain);

	unsigned char crypt_buf[4096] = {0};
	int crypt_len = 0;

	char plain2[4096] = { 0 };
	int plain2_len = 0;


	//�û�ʹ�õĺ���-����
	ret = DesEnc(plain, plain_len, crypt_buf, &crypt_len);
	if (ret!=0)
	{
		printf("func DesEnc() err: %d \n", ret);
		return ret;
	}

	//�û�ʹ�ú���des����
	ret = DesDec(crypt_buf, crypt_len, plain2, &plain2_len);
	if (ret != 0)
	{
		printf("func DesEnc() err: %d \n", ret);
		return ret;
	}
	
	if (plain_len!=plain2_len)
	{
		ret = -2;
		printf("���󣺳��Ȳ�һ��\n");
		return ret;
	}

	if (memcmp(plain2, plain, plain_len) == 0) {
		printf("���ܽ�����ȷ\n");
	}
	else {
		printf("���ܽ��ܴ���\n");
	}
	
	printf("end...\n");
	system("pause");
	return ret;
}