#pragma once
/****************************************!
*@brief
*@author ZhangYunjia
*@date   2019/5/14/13:47

****************************************/

#include<iostream>
#include "socket_protocol.h"
using namespace std;


class sck_factory_2 :public socket_protocol
{
public:
	//�ͻ��˳�ʼ�� ��ȡhandle����
	virtual int cltSocketInit( /*out*/);

	//�ͻ��˷�����
	virtual int cltSocketSend(unsigned char *buf /*in*/, int buflen /*in*/);

	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char *buf /*in*/, int *buflen /*in out*/);

	//�ͻ����ͷ���Դ
	virtual int cltSocketDestory(/*in*/);

private:
	unsigned char* p;
	int len;

};