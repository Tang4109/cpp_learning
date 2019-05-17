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
my_vector<T>::my_vector(int size)//构造函数
{
	m_space = new T[size];
	m_len = size;

}
template <typename T>
my_vector<T>::my_vector(const my_vector &obj)//copy构造函数
{
	//根据my_v1的大小分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy数据
	for (int i=0;i<m_len;i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
my_vector<T>::~my_vector()//析构函数
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
	//先把a2的旧的内存释放掉
	if (m_space!=NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
	//根据a1分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	//copy数据
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}

	return *this;//a2=a1.返回a2的自身
}

template <typename T>
T my_vector<T>::get_len()
{
	return m_len;
}

