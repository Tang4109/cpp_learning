/****************************************!
*@brief  友元函数
*@author ZhangYunjia
*@date   2019/4/25/15:25

****************************************/

#include<iostream>

using namespace std;

class A {
private:
	int a;
	int b;

public:
	//友元函数的声明只要放在类中就行
	friend void modify_A(A *p,int _a, int _b);
	A(int a, int b) {
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

void modify_A(A *p,int _a=0,int _b=0) {

	p->a = _a;
	p->b = _b;
}


int main()
{

	A a1(1, 2);
	//cout<<a1.get_A()<<endl;
	a1.print_A();
	modify_A(&a1, 300);
	a1.print_A();



	cout << "end.." << endl;
	system("pause");
	return 0;
}