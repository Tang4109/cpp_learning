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
	my_vector(int size = 0);//���캯��
	my_vector(const my_vector &obj);//copy���캯��
	~my_vector();//��������
public:
	T& operator[](int index);
	my_vector& operator=(my_vector &obj);

public:
	T get_len();

protected:
	T* m_space;
	int m_len;

};