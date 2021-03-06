/****************************************!
*@brief  日志功能
*@author ZhangYunjia
*@date   2019/5/10/11:02

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"itcastlog.h"


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
	//printf("func cltSocketInit() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketInit begin.");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
	if (handle_ ==NULL)
	{
		ret = -1;
		//printf("func cltSocketInit err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketInit err,ret:%d\n", ret);
		return ret;
	}
	memset(handle_, 0, sizeof(SCK_HANDLE));
	strcpy(handle_->ip, "192.168.1.1");
	handle_->port = 8081;
	*handle = handle_;

	//printf("func cltSocketInit() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketInit end.");
	return ret;
}

//客户端发报文
__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/) {
	int ret = 0;
	if (handle==NULL||buf==NULL)
	{
		ret = -2;
		//printf("func cltSocketSend err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketSend err,ret:%d\n", ret);
		return ret;
	}

	//printf("func cltSocketSend() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketSend begin.");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	handle_->p = (unsigned char*)malloc(buflen * sizeof(unsigned char));
	if (handle_->p == NULL) {
		ret = -3;
		//printf("func cltSocketSend err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketSend err,ret:%d\n", ret);
		return ret;
	}
	memcpy(handle_->p, buf, buflen);
	handle_->p_len = buflen;
	//printf("func cltSocketSend() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketSend end.");
	return ret;
}

//客户端收报文
__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *out_buf /*in*/, int *outbuflen /*in out*/) {
	int ret = 0;
	if (handle == NULL || out_buf == NULL|| outbuflen ==NULL)
	{
		ret = -4;
		//printf("func cltSocketRev err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketRev err,ret:%d\n", ret);
		return ret;
	}

	//printf("func cltSocketRev() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev begin.");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	memcpy(out_buf, handle_->p, handle_->p_len);
	*outbuflen = handle_->p_len;
	//printf("func cltSocketRev() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev end.");
	return ret;
}

//客户端释放资源
__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/) {

	int ret = 0;
	if (handle == NULL)
	{
		ret = -5;
		//printf("func cltSocketDestory err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketDestory err,ret:%d\n", ret);
		return ret;
	}

	//printf("func cltSocketDestory() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketDestory begin.");
	SCK_HANDLE* handle_ = NULL;
	handle_ = (SCK_HANDLE*)handle;
	if (handle_->p) {
		free(handle_->p);

	}
	free(handle_);
	//printf("func cltSocketDestory() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketDestory end.");
	return ret;
}
//////////////////////////////////////////////////////////////////////////
//api接口2
__declspec(dllexport)
int cltSocketInit2(void **handle) {

	return cltSocketInit(handle);
}

//客户端发报文
__declspec(dllexport)
int cltSocketSend2(void *handle, unsigned char *buf, int buflen) {

	return cltSocketSend(handle,buf,buflen);
}
//客户端收报文
__declspec(dllexport)
int cltSocketRev2(void *handle, unsigned char **out_buf, int *outbuflen) {

	int ret = 0;
	if (handle == NULL || out_buf == NULL || outbuflen == NULL)
	{
		ret = -4;
		//printf("func cltSocketRev2 err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketRev2 err,ret:%d\n", ret);
		return ret;
	}

	//printf("func cltSocketRev2() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev2 begin.");
	SCK_HANDLE* handle_ = NULL;
	unsigned char* tmp = NULL;

	handle_ = (SCK_HANDLE*)handle;
	tmp = (unsigned char*)malloc(handle_->p_len);//函数内分配内存空间
	if (tmp==NULL)
	{
		ret = -5;
		//printf("func cltSocketRev2 err:%d\n", ret);
		ITCAST_LOG(__FILE__, __LINE__, LogLevel[4], 0, "func cltSocketRev2 err,ret:%d\n", ret);
		return ret;

	}

	memcpy(tmp, handle_->p, handle_->p_len);
	*outbuflen = handle_->p_len;
	*out_buf = tmp;//间接赋值
	//printf("func cltSocketRev2() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev2 end.");
	return ret;
}
__declspec(dllexport)
int cltSocketRev2_Free(unsigned char **buf) {
	int ret = 0;
	if (buf==NULL)
	{
		ret = -6;
		return ret;
	}
	//printf("func cltSocketRev2_Free() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev2_Free begin.");
	if (*buf != NULL)
	{
		free(*buf);
	}
	*buf = NULL;//间接修改实参的值
	//printf("func cltSocketRev2_Free() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketRev2_Free end.");
	return ret;
}
//客户端释放资源
__declspec(dllexport)
int cltSocketDestory2(void **handle) {
	int ret = 0;

	SCK_HANDLE* tmp = NULL;
	if (handle==NULL)
	{
		ret = -7;
		return ret;

	}
	//printf("func cltSocketDestory2() begin.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketDestory2 begin.");

	tmp = *handle;
	if (tmp!=NULL)
	{
		if (tmp->p)
		{
			free(tmp->p);
		}
		free(tmp);
	}
	*handle = NULL;
	//printf("func cltSocketDestory2() end.\n");
	ITCAST_LOG(__FILE__, __LINE__, LogLevel[2], 0, "func cltSocketDestory2 end.");
	return ret;
}