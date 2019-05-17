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
	return out;
}


template <typename T>
my_vector<T>::my_vector(int size)//构造函数
{

}
template <typename T>
my_vector<T>::my_vector(const my_vector &obj)//copy构造函数
{

}

template <typename T>
my_vector<T>::~my_vector()//析构函数
{


}
template <typename T>
T& my_vector<T>::operator[](int index)
{

	return m_space[index];
}

template <typename T>
my_vector<T>& my_vector<T>::operator=(my_vector<T> &obj)
{

	return *this;
}

template <typename T>
T my_vector<T>::get_len()
{
	return m_len;
}

