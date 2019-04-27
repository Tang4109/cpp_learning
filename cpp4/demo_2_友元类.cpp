/****************************************!
*@brief  友元类
*@author ZhangYunjia
*@date   2019/4/25/16:33

****************************************/

#include<iostream>
using namespace std;


class A {
private:
	int a;
	int b;

public:
	/*
	若B类是A类的友员类，则B类的所有成员函数都是A类的友员函数
	友员类通常设计为一种对数据操作或类之间传递消息的辅助类
	*/

	friend class B;

	A(int a=0, int b=0) {
		this->a = a;
		this->b = b;

	}
	int get_A() {

		return this->a;
	}
	void print_A() {
		cout << this->a << endl;
		cout << this->b << endl;
	}

};

class B {
private:
	A object_a;
public:
	void set_A(int a,int b) {

		object_a.a = a;
		object_a.b = b;
	}
	void print_A() {
		cout << object_a.a << endl;
		cout << object_a.b << endl;

	}

};

int main()
{
	B b1;
	b1.set_A(10, 20);
	b1.print_A();
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
