/****************************************!
*@brief
*@author ZhangYunjia
*@date   2019/5/14/13:51

****************************************/

#include<iostream>
#include "sck_factory_2.h"
using namespace std;

//�ͻ��˳�ʼ�� ��ȡhandle����
int sck_factory_2::cltSocketInit( /*out*/)
{
	p = NULL;
	len = 0;

	return 0;
}

//�ͻ��˷�����
int sck_factory_2::cltSocketSend(unsigned char *buf /*in*/, int buflen /*in*/)
{
	/*
	Type* pointer = new Type[N];
	delete[] pointer;
	*/

	p = new unsigned char[buflen + 1];//sizeof(unsigned char)*
	if (p == NULL) {
		cout << "�����ڴ�ʧ��" << endl;
		return -1;
	}
	memcpy(p, buf, buflen);
	p[buflen] = '\0';
	len = buflen;
	return 0;
}

//�ͻ����ձ���
int sck_factory_2::cltSocketRev(unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	if (buf == NULL || buflen == NULL)
	{
		cout << "��ַ����" << endl;
		return -2;
	}
	*buflen = len;

	memcpy(buf, p, len);
	buf[len] = '\0';
	cout << "���յ��ı��ģ�" << endl;
	cout << buf << endl;

	return 0;
}

//�ͻ����ͷ���Դ
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
