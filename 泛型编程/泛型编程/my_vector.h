#pragma once
/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/17/10:10

****************************************/

#include<iostream>

using namespace std;

template<typename T>
class my_vector
{
	friend ostream& operator<< <T>(ostream &out, my_vector &obj);

public:
	my_vector(int size = 0);//构造函数
	my_vector(const my_vector &obj);//copy构造函数
	~my_vector();//析构函数
public:
	T& operator[](int index);
	my_vector& operator=(my_vector &obj);

public:
	T get_len();

protected:
	T* m_space;
	int m_len;

};