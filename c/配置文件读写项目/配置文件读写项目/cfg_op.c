

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
		if (pTmp==NULL)//没有等号
		{
			continue;
		}
		pTmp = strstr(buf, pKey);
		if (pTmp == NULL)//判断所在行是不是有key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);
		pTmp = strchr(pTmp, '=');
		if (pTmp == NULL)//没有等号
		{
			continue;
		}
		
		pTmp = pTmp + 1;
		//获取value 起点
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
					//没有配置value
					//printf("配置项:%s 没有配置value \n", pKey);
					goto End;
				}
				break;
			}
		}

		//获取valude结束点
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

		//赋值
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

	fseek(fp, 0L, SEEK_END); //把文件指针从0位置开始，移动到文件末尾
	//获取文件长度;
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	if (length > 1024 * 8)
	{
		rv = -3;
		printf("文件超过1024*8, nunsupport");
		goto End;
	}

	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}

		//key关键字是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) //key关键字不在本行， copy到filebuf中
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else  //key关键在在本行中，替换旧的行，再copy到filebuf中 
		{
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在key
			iTag = 1;
		}
	}

	//若key关键字，不存在 追加
	if (iTag == 0)
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else //若key关键字，存在，则重新创建文件
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL; //避免野指针
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