/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/14/16:21

****************************************/

#include<iostream>
#include "enc_dec_1.h"
#include "des.h"
using namespace std;





int enc_dec_1::enc_data(unsigned char* plain, int plain_len, unsigned char* cryptdata, int* crypt_len)
{
	int ret = 0;
	//�û�ʹ�õĺ���
	ret = DesEnc(plain,plain_len,cryptdata,crypt_len);
	if (ret != 0)
	{
		cout << "func DesEnc() err: " << ret << endl;
		return ret;
	}

	return ret;
}
int enc_dec_1::dec_data(unsigned char* cryptdata, int crypt_len, unsigned char* plain, int* plain_len)
{
	int ret = 0;
	//�û�ʹ�ú���des����
	ret = DesDec(cryptdata, crypt_len, plain, plain_len);
	if (ret != 0)
	{
		cout << "func DesDec() err: " << ret << endl;
		return ret;
	}
	cout << "���ܺ�ı��ģ�" << endl;
	cout << plain << endl;
	return ret;
}

