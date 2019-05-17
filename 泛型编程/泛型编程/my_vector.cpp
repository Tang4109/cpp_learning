/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/17/10:20

****************************************/

#include<iostream>
#include "my_vector.h"
using namespace std;

template <typename T>
ostream& operator<<(ostream &out, my_vector<T> &obj)
{
	for (int i=0;i<obj.m_len;i++)
	{
		out << obj.m_space[i] << " ";
	}
	out << endl;
	return out;
}


template <typename T>
my_vector<T>::my_vector(int size)//���캯��
{
	m_space = new T[size];
	m_len = size;

}
template <typename T>
my_vector<T>::my_vector(const my_vector &obj)//copy���캯��
{
	//����my_v1�Ĵ�С�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy����
	for (int i=0;i<m_len;i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
my_vector<T>::~my_vector()//��������
{
	if (m_space!=NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}

}
template <typename T>
T& my_vector<T>::operator[](int index)
{
	return m_space[index];
}

template <typename T>
my_vector<T>& my_vector<T>::operator=(my_vector<T> &obj)
{
	//�Ȱ�a2�ľɵ��ڴ��ͷŵ�
	if (m_space!=NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
	//����a1�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy����
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}

	return *this;//a2=a1.����a2������
}

template <typename T>
T my_vector<T>::get_len()
{
	return m_len;
}

