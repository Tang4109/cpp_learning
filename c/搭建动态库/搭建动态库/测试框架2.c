/****************************************!
*@brief  日志功能
*@author ZhangYunjia
*@date   2019/5/10/14:59

****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "socketclientdll.h"


int main()
{

	int ret = 0;
	void *handle = NULL;
	char buf[128];
	int buf_len = -3;
	strcpy(buf, "zzz");

	//char out_buf[128];//常量指针，不能被修改，所以将out_buf定义为普通指针
	//int out_buf_len;

	char* out_buf=NULL;
	int out_buf_len = 0;

	ret = cltSocketInit2(&handle /*out*/);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端发报文
	ret = cltSocketSend2(handle /*in*/, buf /*in*/, buf_len /*in*/);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端收报文
	ret = cltSocketRev2(handle, &out_buf, &out_buf_len);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	ret = cltSocketRev2_Free(&out_buf);//避免野指针，同时将out_buf置为NULL
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端释放资源
	cltSocketDestory2(handle/*in*/);

	printf("end...\n");
	system("pause");
	return 0;
}


//int mainx()
//{
//
//	ITCAST_LOG(__FILE__, __LINE__, LogLevel[1], 0, "1111");
//	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "2222");
//	ITCAST_LOG(__FILE__, __LINE__, LogLevel[3], 0, "3333");
//	ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "4444");
//
//
//	
//	printf("end...\n");
//	system("pause");
//	return 0;
//}