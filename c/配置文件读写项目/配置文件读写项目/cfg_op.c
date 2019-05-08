

/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/8/13:59

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "cfg_op.h"

#define MaxLine 2048

int GetCfgItem(char* pFileName, char* pKey, char* pValue, int* pValueLen) {

	FILE *fp = NULL;
	char buf[MaxLine];
	char *pTmp = NULL, *pEnd = NULL, *pBegin = NULL;

	fp = fopen(pFileName,"r");
	if (fp==NULL)
	{
		return -1;
	}
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, MaxLine,fp);
		//printf("buf:%s", buf);

		pTmp = strchr(buf, '=');
		if (pTmp==NULL)//û�еȺ�
		{
			continue;
		}
		pTmp = strstr(buf, pKey);
		if (pTmp == NULL)//�ж��������ǲ�����key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');
		if (pTmp == NULL)//û�еȺ�
		{
			continue;
		}
		
		pTmp = pTmp + 1;
		//��ȡvalue ���
		while (1)
		{
			if (*pTmp == ' ')
			{
				pTmp++;
			}
			else
			{
				pBegin = pTmp;
				if (*pBegin == '\n')
				{
					//û������value
					//printf("������:%s û������value \n", pKey);
					goto End;
				}
				break;
			}
		}

		//��ȡvalude������
		while (1)
		{
			if ((*pTmp == ' ' || *pTmp == '\n'))
			{
				break;
			}
			else
			{
				pTmp++;
			}
		}
		pEnd = pTmp;

		//��ֵ
		*pValueLen = pEnd - pBegin;
		memcpy(pValue, pBegin, pEnd - pBegin);
	}

End:
	if (fp == NULL)
	{
		fclose(fp);
	}
	return 0;

}
int WriteCfgItem(char* pFileName, char* pKey, char* pValue, int ValueLen) {
	int		rv = 0, iTag = 0, length = 0;
	FILE	*fp = NULL;
	char	lineBuf[MaxLine];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024 * 8] = { 0 };

	if (pFileName == NULL || pKey == NULL || pValue == NULL)
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		//goto End;
	}

	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t");
		if (fp == NULL)
		{
			rv = -3;
			printf("fopen() err. \n");
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END); //���ļ�ָ���0λ�ÿ�ʼ���ƶ����ļ�ĩβ
	//��ȡ�ļ�����;
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	if (length > 1024 * 8)
	{
		rv = -3;
		printf("�ļ�����1024*8, nunsupport");
		goto End;
	}

	while (!feof(fp))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}

		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) //key�ؼ��ֲ��ڱ��У� copy��filebuf��
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else  //key�ؼ����ڱ����У��滻�ɵ��У���copy��filebuf�� 
		{
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//������key
			iTag = 1;
		}
	}

	//��key�ؼ��֣������� ׷��
	if (iTag == 0)
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else //��key�ؼ��֣����ڣ������´����ļ�
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL; //����Ұָ��
		}

		fp = fopen(pFileName, "w+t");
		if (fp == NULL)
		{
			rv = -4;
			printf("fopen() err. \n");
			goto End;
		}
		fputs(filebuf, fp);
		//fwrite(filebuf, sizeof(char), strlen(filebuf), fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return rv;
}