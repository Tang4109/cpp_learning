/****************************************!
*@brief  数组操作符重载
*@author ZhangYunjia
*@date   2019/4/26/10:32

****************************************/

#pragma once

#include<iostream>

using namespace std;
//类的声明
class Array
{
private:
	int m_length = 0;
	int *m_space = NULL;

public:
	Array(int length);
	Array(const Array& obj);
	~Array();
public:
	void set_data(int index, int value);
	int get_data(int index);
	int length();

public:
	int& operator[](int i);

};
