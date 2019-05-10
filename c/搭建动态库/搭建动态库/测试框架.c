/****************************************!
*@brief  搭建动态库（实现初始化/发送/接收/内存释放）
*@author ZhangYunjia
*@date   2019/5/10/10:37
****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main()
{

	int ret = 0;
	void *handle = NULL;
	char buf[128];
	int buf_len = 3;
	strcpy(buf, "zzz");

	char out_buf[128];
	int out_buf_len = 3;

	ret = cltSocketInit(&handle /*out*/);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端发报文
	ret = cltSocketSend(handle /*in*/, buf /*in*/, buf_len /*in*/);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端收报文
	ret = cltSocketRev(handle /*in*/, out_buf /*in*/, &out_buf_len /*in out*/);
	if (ret != 0)
	{
		printf("func cltSocketInit() err: %d\n", ret);
		return ret;
	}

	//客户端释放资源
	cltSocketDestory(handle/*in*/);

	printf("end...\n");
	system("pause");
	return 0;
}