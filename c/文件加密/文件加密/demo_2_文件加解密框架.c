/****************************************!
*@brief  文件加解密框架
*@author ZhangYunjia
*@date   2019/5/9/9:40

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "des.h"

int FileSymEnc(const char* pfile1, const char* pfile2)
{
	int ret = 0;
	unsigned char plain[4096];
	int plain_len = 0;
	int plain_len2 = 0;

	unsigned char* crypt_buf[4096] = { 0 };
	int crypt_len = 0;
	int crypt_len2 = 0;

	//打开文件
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	fp1 = fopen(pfile1, "rb");
	if (fp1==NULL)
	{
		goto END;
	}

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto END;
	}
	//拷贝数据
	while (!feof(fp1))
	{
		plain_len = fread(plain, 1, 4096, fp1);
		if (feof(fp1))//读完数据之后判断是否文件结束
		{
			break;
		}
		//加密
		ret = DesEnc(plain, plain_len, crypt_buf, &crypt_len);
		if (ret != 0)
		{
			printf("func DesEnc() err: %d \n", ret);
			goto END;
		}


		//等于4k的数据块（循环）
		crypt_len2 = fwrite(crypt_buf, 1, crypt_len, fp2);
		if (crypt_len2 != crypt_len)
		{
			ret = -3;
			printf("写密文失败，请检查是否磁盘已满.\n");
			goto END;
		}
	}
	//加密
	ret = DesEnc(plain, plain_len, crypt_buf, &crypt_len);
	if (ret != 0)
	{
		printf("func DesEnc() err: %d \n", ret);
		goto END;
	}

	//小于4k的数据块
	crypt_len2 = fwrite(crypt_buf, 1, crypt_len, fp2);
	if (crypt_len2 != crypt_len)
	{
		ret = -3;
		printf("写密文失败，请检查是否磁盘已满.\n");
		goto END;
	}
	

END:
	
	if (fp1!=NULL)
	{
		fclose(fp1);
	}
	
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	

	return 0;
}


int main()
{
	int ret = 0;
	const char* file1 = "c:/book/2.txt";
	const char* file2 = "c:/book/22enc.txt";

	ret = FileSymEnc(file1, file2);
	if (ret != 0) {
		printf("func FileSymEnc() err: %d\n", ret);
		return ret;
	}
	
	printf("end...\n");
	system("pause");
	return ret;
}