/****************************************!
*@brief  继承中的static关键字
*@author ZhangYunjia
*@date   2019/4/29/8:26

****************************************/

#include<iostream>

using namespace std;

class A {
public:
	static int a;
	int b;
public:
	void get() {
		cout << a << " "<< b << endl;
	}
};

int A::a = 100;//初始化+分配内存

class B :public A {
public:
	int b;
	int c;
public:
	void get() {

		cout << a << endl;
		cout << b << endl;
	}

};

int main()
{
	B b1;
	b1.b=100;
	b1.get();

	A a1;
	a1.b = 200;
	a1.get();

	a1.a = 300;
	b1.get();
	a1.get();

	cout << "end.." << endl;
	system("pause");
	return 0;
}