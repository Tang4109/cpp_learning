#pragma once
/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/14/11:18

****************************************/

#include<iostream>

using namespace std;

class socket_protocol
{
public:
	//客户端初始化 获取handle上下
	virtual int cltSocketInit( /*out*/) = 0;
	
	 //客户端发报文
	virtual int cltSocketSend(unsigned char *buf /*in*/, int buflen /*in*/) = 0;

	 //客户端收报文
	virtual int cltSocketRev(unsigned char *buf /*in*/, int *buflen /*in out*/) = 0;
	
	 //客户端释放资源
	virtual int cltSocketDestory(/*in*/) = 0;

};