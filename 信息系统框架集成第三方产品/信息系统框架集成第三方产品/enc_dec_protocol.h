#pragma once
/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/14/16:06

****************************************/

#include<iostream>

using namespace std;

class enc_dec_protocol
{
public:
	virtual int enc_data(unsigned char* plain, int plain_len, unsigned char* cryptdata, int* crypt_len) = 0;
	virtual int dec_data(unsigned char* cryptdata, int crypt_len, unsigned char* plain, int* plain_len) = 0;

protected:
private:
};