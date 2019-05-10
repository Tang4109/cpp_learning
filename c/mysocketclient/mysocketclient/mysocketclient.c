/****************************************!
*@brief  搭建动态库（实现初始化/发送/接收/内存释放）
*@author ZhangYunjia
*@date   2019/5/10/11:02

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct _SCK_HANDLE {

	char version[64];
	char ip[128];
	int port;
	unsigned char* p;
	int p_len;

}SCK_HANDLE; //动态库内部的数据类型，不想让上层应用知道-数据类型的封装

//客户端初始化 获取handle上下
__declspec(dllexport)
int cltSocketInit(void **handle /*out*/) {
	int ret = 0;
	printf("func cltSocketInit() begin.\n");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
	if (handle_ ==NULL)
	{
		ret = -1;
		printf("func cltSocketInit err:%d\n", ret);
		return ret;
	}
	memset(handle_, 0, sizeof(SCK_HANDLE));
	strcpy(handle_->ip, "192.168.1.1");
	handle_->port = 8081;
	*handle = handle_;

	printf("func cltSocketInit() end.\n");

	return ret;
}

//客户端发报文
__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/) {
	int ret = 0;
	if (handle==NULL||buf==NULL)
	{
		ret = -2;
		printf("func cltSocketSend err:%d\n", ret);
		return ret;
	}

	printf("func cltSocketSend() begin.\n");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	handle_->p = (unsigned char*)malloc(buflen * sizeof(unsigned char));
	if (handle_->p == NULL) {
		ret = -3;
		printf("func cltSocketSend err:%d\n", ret);
		return ret;
	}
	memcpy(handle_->p, buf, buflen);
	handle_->p_len = buflen;
	printf("func cltSocketSend() end.\n");
	return ret;
}

//客户端收报文
__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *out_buf /*in*/, int *outbuflen /*in out*/) {
	int ret = 0;
	if (handle == NULL || out_buf == NULL|| outbuflen ==NULL)
	{
		ret = -4;
		printf("func cltSocketRev err:%d\n", ret);
		return ret;
	}

	printf("func cltSocketRev() begin.\n");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	memcpy(out_buf, handle_->p, handle_->p_len);
	*outbuflen = handle_->p_len;
	printf("func cltSocketRev() end.\n");
	return ret;
}

//客户端释放资源
__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/) {

	int ret = 0;
	if (handle == NULL)
	{
		ret = -5;
		printf("func cltSocketDestory err:%d\n", ret);
		return ret;
	}

	printf("func cltSocketDestory() begin.\n");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	if (handle_->p) {
		free(handle_->p);

	}
	free(handle_);
	printf("func cltSocketDestory() end.\n");
	return ret;
}