/****************************************!
*@brief  框架类
*@author ZhangYunjia
*@date   2019/5/14/11:17

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "socket_protocol.h"
#include "sck_factory_1.h"
#include "sck_factory_2.h"
#include "enc_dec_protocol.h"
#include "enc_dec_1.h"
#include "des.h"
using namespace std;

class main_op :public sck_factory_1,public sck_factory_2,public enc_dec_1
{
private:
	socket_protocol* sp;
	enc_dec_protocol* ed;

public:
	main_op()
	{
		sp = NULL;
		ed = NULL;
	}
	main_op(socket_protocol* sp_, enc_dec_protocol* ed_)
	{
		sp = sp_;
		ed = ed_;
	}
	//~main_op() {
	//	delete sp;
	//	delete ed;
	//}
public:
	void set_sp(socket_protocol* sp_)
	{
		sp = sp_;
	}

	void set_ed(enc_dec_protocol* ed_)
	{
		ed = ed_;
	}
public:
	//面向抽象类编程框架实现
	int sck_send_rec_enc_dec(unsigned char *in, int in_len, unsigned char* out, int* out_len)
	{
		int ret = 0;
		unsigned char buf[4096] = { 0 };
		int buf_len = 0;
		ret = sp->cltSocketInit();
		if (ret != 0)
		{
			goto end;
		}


		//加密
		ret = ed->enc_data(in, in_len, buf, &buf_len);
		if (ret != 0)
		{
			goto end;
		}

		ret = sp->cltSocketSend(buf, buf_len);
		if (ret != 0)
		{
			goto end;
		}
		ret = sp->cltSocketRev(buf, &buf_len);
		if (ret != 0)
		{
			goto end;
		}
		//解密
		ret = ed->dec_data(buf, buf_len, out, out_len);
		if (ret != 0)
		{
			goto end;
		}


	end:
		ret = sp->cltSocketDestory();

		return ret;
	}



};


int main()
{
	int ret = 0;
	unsigned char in[4096] = { 0 };

	int in_len = 0;
	unsigned char out[4096] = { 0 };
	int out_len = 0;

	strcpy((char *)in, "zyjzyjzyjzyjzyjzyjzyjzyj");
	in_len = 7;

	main_op* my_main_op = new main_op;
	

	socket_protocol* sp = NULL;
	cout << "您希望使用厂商1/2 ?" << endl;
	cout << "我希望使用厂商: ";
	int factory = 1;
	cin >> factory;
	if (factory == 1)
	{
		sp = new sck_factory_1;
		my_main_op->set_sp(sp);
		in_len = 7;
	}
	else if (factory == 2)
	{
		sp = new sck_factory_2;
		my_main_op->set_sp(sp);
		in_len = 5;
	}

	enc_dec_protocol* ed = NULL;
	ed = new enc_dec_1;
	my_main_op->set_ed(ed);



	ret = my_main_op->sck_send_rec_enc_dec(in, in_len, out, &out_len);
	if (ret != 0) {
		cout << "func sck_send_rec() err:" << ret << endl;
		return ret;
	}

	delete sp;
	delete ed;
	delete my_main_op;
	cout << "end.." << endl;
	system("pause");
	return ret;
}