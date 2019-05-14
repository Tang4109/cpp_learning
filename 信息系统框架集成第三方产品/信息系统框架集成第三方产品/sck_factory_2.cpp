/****************************************!
*@brief
*@author ZhangYunjia
*@date   2019/5/14/13:51

****************************************/

#include<iostream>
#include "sck_factory_2.h"
using namespace std;

//客户端初始化 获取handle上下
int sck_factory_2::cltSocketInit( /*out*/)
{
	p = NULL;
	len = 0;

	return 0;
}

//客户端发报文
int sck_factory_2::cltSocketSend(unsigned char *buf /*in*/, int buflen /*in*/)
{
	/*
	Type* pointer = new Type[N];
	delete[] pointer;
	*/

	p = new unsigned char[buflen + 1];//sizeof(unsigned char)*
	if (p == NULL) {
		cout << "分配内存失败" << endl;
		return -1;
	}
	memcpy(p, buf, buflen);
	p[buflen] = '\0';
	len = buflen;
	return 0;
}

//客户端收报文
int sck_factory_2::cltSocketRev(unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	if (buf == NULL || buflen == NULL)
	{
		cout << "地址有误" << endl;
		return -2;
	}
	*buflen = len;

	memcpy(buf, p, len);
	buf[len] = '\0';
	cout << "接收到的报文：" << endl;
	cout << buf << endl;

	return 0;
}

//客户端释放资源
int sck_factory_2::cltSocketDestory(/*in*/)
{
	if (p != NULL)
	{
		delete[] p;
		p = NULL;
		len = 0;
	}
	return 0;
}
