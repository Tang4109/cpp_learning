/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/14/11:17

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "socket_protocol.h"
#include "sck_factory_1.h"
#include "sck_factory_2.h"
using namespace std;

//面向抽象类编程框架实现
int sck_send_rec(socket_protocol* sp, unsigned char *in,int in_len,unsigned char* out,int* out_len)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret!=0)
	{
		goto end;
	}

	ret = sp->cltSocketSend(in, in_len);
	if (ret != 0)
	{
		goto end;
	}
	ret = sp->cltSocketRev(out, out_len);
	if (ret != 0)
	{
		goto end;
	}

end:
	ret = sp->cltSocketDestory();

	return ret;
}

int main()
{
	int ret = 0;
	unsigned char in[4096] = { 0 };

	int in_len = 0;
	unsigned char out[4096] = { 0 };
	int out_len = 0;

	strcpy((char *)in, "zyjzyjzyjzyjzyjzyjzyjzyj");
	in_len = 9;

	socket_protocol* sp = NULL;
	cout << "您希望使用厂商1/2 ?" << endl;
	cout << "我希望使用厂商: " ;
	int factory = 1;
	cin >> factory;
	if (factory==1)
	{
		sp = new sck_factory_1;
		in_len = 9;
	}
	else if (factory == 2)
	{
		sp = new sck_factory_2;
		in_len = 12;
	}
	
	


	ret = sck_send_rec(sp, in, in_len, out, &out_len);
	if (ret != 0) {
		cout << "func sck_send_rec() err:" << ret << endl;
		return ret;
	}
	
	delete sp;
	cout<<"end.."<<endl;
	system("pause");
	return ret;
}