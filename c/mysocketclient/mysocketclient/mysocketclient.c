/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/10/11:02

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//客户端初始化 获取handle上下
__declspec(dllexport)
int cltSocketInit(void **handle /*out*/) {

	printf("func cltSocketInit() begin.\n");
	printf("func cltSocketInit() end.\n");

	return 0;
}

//客户端发报文
__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/) {

	return 0;
}

//客户端收报文
__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/) {

	return 0;
}

//客户端释放资源
__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/) {

	return 0;
}