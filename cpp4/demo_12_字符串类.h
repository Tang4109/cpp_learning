
/****************************************!
*@brief  字符串类(等号/数组下标/左移/双等号/不等号/小于/大于/输入 运算符重载)
*@author ZhangYunjia
*@date   2019/4/26/15:24

****************************************/
#pragma once
#include<iostream>

using namespace std;

class my_string
{
	friend ostream& operator<<(ostream &out, my_string& s);
	friend istream& operator>>(istream& in, my_string& s);
public:
	my_string(int length);
	my_string(const char* p);
	my_string(const my_string& s);
	~my_string();

public:
	my_string & operator=(const char*p);
	my_string& operator=(const my_string& s);
	char& operator[](int index);

	bool operator==(const char*p);
	bool operator==(const my_string& s);
	bool operator!=(const char*p);
	bool operator!=(const my_string& s);

	int operator<(const char *p);
	int operator>(const char *p);
	int operator<(const my_string& s);
	int operator>(const my_string& s);

	

public:
	void print();
	char* c_str() {
		return m_p;
	}
	const char* c_str2() {
		return m_p;
	}
	int length() {
		return len;
	}


protected:
private:
	int len;
	char* m_p;
};
