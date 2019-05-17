/****************************************!
*@brief  友元函数写在类的外部的方法
*@author ZhangYunjia
*@date   2019/5/16/21:00

****************************************/

#include<iostream>

using namespace std;

template<typename T>
class complex
{
	//friend ostream& operator<<(ostream &out, complex &c3);
	friend ostream& operator<< <T>(ostream &out, complex &c3);

	friend complex my_sub(complex &c1, complex &c2) {
		complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}

public:
	complex(T a_, T b_);
	void print_com();
	complex operator+(complex &c2);

private:
	T a;
	T b;
};


//运算符重载的正规写法:<<>>只能用友元函数，其他运算符重载都要写成成员函数，不要滥用友元函数
template<typename T>
//友元函数是全局函数，不属于类，所以不能加类的域名作用符
ostream& operator<<(ostream &out, complex<T> &c3) {

	out<< "a:" << c3.a << endl << "b:" << c3.b << endl;
	return out;
}

//构造函数在类的外部的实现
template<typename T>
complex<T>::complex(T a_, T b_) {
	a = a_;
	b = b_;
}
//成员函数在类的外部实现运算符重载
template<typename T>
void complex<T>::print_com() {
	cout << "a:" << a << endl << "b:" << b << endl;
}

template<typename T>
complex<T> complex<T>::operator+(complex<T> &c2) {
	complex tmp(a + c2.a, b + c2.b);
	return tmp;
}

int main()
{

	complex<int>c1(1, 2);
	complex<int>c2(3, 4);

	//运算符重载
	complex<int>c3 = c1 + c2;
	cout << c3 << endl;

	//滥用友元函数
	{
		complex<int>c4 = my_sub(c1, c2);
		cout << c4 << endl;


	}



	cout << "end.." << endl;
	system("pause");
	return 0;
}