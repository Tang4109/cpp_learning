/****************************************!
*@brief  继承中的同名成员变量和函数
*@author ZhangYunjia
*@date   2019/4/28/17:03

****************************************/

#include<iostream>

using namespace std;

class A {
public:
	int a;
	int b;
public:
	void get() {
		cout << b << endl;
	}
};

class B :public A {
public:
	int b;
	int c;
public:
	void get() {
		cout << b << endl;
	}

};

int main()
{
	A a1;
	B b1;

	b1.b = 10;
	b1.A::b = 20;
	a1.get();
	b1.get();
	b1.A::get();

	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}