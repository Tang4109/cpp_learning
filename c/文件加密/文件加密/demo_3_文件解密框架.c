/****************************************!
*@brief  �ļ����ܿ��
*@author ZhangYunjia
*@date   2019/5/9/14:17

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int FileSymDec(const char* pfile1, const char* pfile2)
{
	int ret = 0;
	unsigned char plain[4096];
	int plain_len = 0;
	int plain_len2 = 0;

	unsigned char* crypt_buf[4096] = { 0 };
	int crypt_len = 0;
	int crypt_len2 = 0;

	//���ļ�
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		goto END;
	}

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto END;
	}
	//��������
	while (!feof(fp1))
	{
		crypt_len = fread(crypt_buf, 1, 4096, fp1);
		if (feof(fp1))//��������֮���ж��Ƿ��ļ�����
		{
			break;
		}
		//����
		ret = DesDec_raw(crypt_buf, crypt_len, plain, &plain_len);
		if (ret != 0)
		{
			printf("func DesDec() err: %d \n", ret);
			goto END;
		}


		//����4k�����ݿ飨ѭ����
		plain_len2 = fwrite(plain, 1, plain_len, fp2);
		if (plain_len2 != plain_len)
		{
			ret = -3;
			printf("����д�ļ�ʧ�ܣ������Ƿ��������.\n");
			goto END;
		}
	}
	//����
	ret = DesDec(crypt_buf, crypt_len, plain, &plain_len);
	if (ret != 0)
	{
		printf("func DesDec() err: %d \n", ret);
		goto END;
	}

	//С��4k�����ݿ�
	plain_len2 = fwrite(plain, 1, plain_len, fp2);
	if (plain_len2 != plain_len)
	{
		ret = -3;
		printf("����д�ļ�ʧ�ܣ������Ƿ��������.\n");
		goto END;
	}


END:

	if (fp1 != NULL)
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
	const char* file1 = "c:/book/22enc.txt";
	const char* file2 = "c:/book/22dec.txt";

	ret = FileSymDec(file1, file2);
	if (ret != 0) {
		printf("func FileSymEnc() err: %d\n", ret);
		return ret;
	}

	printf("end...\n");
	system("pause");
	return ret;
}