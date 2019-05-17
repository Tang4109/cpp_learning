/****************************************!
*@brief  不同类型使用不同的静态成员属性
*@author ZhangYunjia
*@date   2019/5/17/9:41

****************************************/

#include<iostream>

using namespace std;

template<typename T>
class A {

public:
	static T m_a;


};

template<typename T>
T A<T>::m_a;


int main()
{
	A<int> a1, a2,a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;

	cout << a1.m_a << endl;
	cout << a2.m_a << endl;
	cout << a3.m_a << endl;
	
	A<char>b1, b2, b3;
	b1.m_a = 'a';
	b2.m_a++;
	b3.m_a++;

	cout << b1.m_a << endl;
	cout << b2.m_a << endl;
	cout << b3.m_a << endl;
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}