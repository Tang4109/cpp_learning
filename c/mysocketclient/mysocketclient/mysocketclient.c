/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/10/11:02

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//�ͻ��˳�ʼ�� ��ȡhandle����
__declspec(dllexport)
int cltSocketInit(void **handle /*out*/) {

	printf("func cltSocketInit() begin.\n");
	printf("func cltSocketInit() end.\n");

	return 0;
}

//�ͻ��˷�����
__declspec(dllexport)
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/) {

	return 0;
}

//�ͻ����ձ���
__declspec(dllexport)
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/) {

	return 0;
}

//�ͻ����ͷ���Դ
__declspec(dllexport)
int cltSocketDestory(void *handle/*in*/) {

	return 0;
}