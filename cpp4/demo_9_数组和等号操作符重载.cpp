/****************************************!
*@brief  ����͵ȺŲ���������
*@author ZhangYunjia
*@date   2019/4/26/10:32

****************************************/
#include<iostream>
#include "demo_9_����͵ȺŲ���������.h"
using namespace std;

//���ʵ��
Array::Array(int length)
{
	m_length = length;
	if (m_length<0)
		m_length = 0;
	m_space = new int[m_length];


}
Array::Array(const Array& obj)
{
	this->m_length = obj.m_length;
	this->m_space = new int[m_length];//�����ڴ�ռ�
									  //���
	for (int i = 0; i<m_length; i++)
	{
		this->m_space[i] = obj.m_space[i];
	}
}
Array::~Array()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_length = 0;
		m_space = NULL;
		//cout << &m_space << endl;
	}

}
//a1.set_data(i, i);
void Array::set_data(int index, int value)
{
	m_space[index] = value;
}
int Array::get_data(int index)
{
	return m_space[index];
}
int Array::length()
{
	return m_length;
}

int& Array::operator[](int i) {

	return m_space[i];
}

Array& Array::operator=(Array &a1) {
	//1.�ͷ�ԭ�����ڴ�ռ�
	if (this->m_space!=NULL)
	{
		delete[] m_space;
		m_length = 0;
	}
	//2.����a1��С�������ڴ�
	m_length = a1.m_length;
	m_space = new int[m_length];
	//3.copy ����
	for (int i=0;i<m_length;i++)
	{
		m_space[i] = a1[i];
	}

	return *this;
}
bool  Array::operator==(Array &a1) {
	if (this->m_length!=a1.m_length)
	{
		return false;
	}
	for (int i=0;i<m_length;i++)
	{
		if (this->m_space[i]!=a1[i])
		{
			return false;
		}
	}

	return true;
}

bool  Array::operator!=(Array &a1) {
	//if (*this==a1)
	//	return false;
	//return true; 
	return !(*this == a1);
}

