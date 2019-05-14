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
	//客户端初始化 获取handle上下
	virtual int cltSocketInit( /*out*/);

	//客户端发报文
	virtual int cltSocketSend(unsigned char *buf /*in*/, int buflen /*in*/);

	//客户端收报文
	virtual int cltSocketRev(unsigned char *buf /*in*/, int *buflen /*in out*/);

	//客户端释放资源
	virtual int cltSocketDestory(/*in*/);

private:
	unsigned char* p;
	int len;

};