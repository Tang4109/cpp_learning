/****************************************!
*@brief  多继承的二义性和虚继承
*@author ZhangYunjia
*@date   2019/4/29/9:10

****************************************/

#include<iostream>

using namespace std;

class base {
public:
	int b;
public:
	void print() {
		cout << b << endl;
	}

};

class base1:virtual public base {
public:
	int b1;
public:
	void print() {
		cout << b1 << endl;
	}

};

class base2:virtual public base {

public:
	int b2;
public:
	void print() {
		cout << b2 << endl;
	}
};

class B :public base1, public base2 {

private:
	int b3;
public:
	void print() {
		cout << b3 << endl;
	}
};


int main()
{

	B b1;
	b1.b1 = 100;
	b1.b2 = 200;
	b1.b = 300;
	b1.base::print();
	b1.base1::print();
	b1.base2::print();


	cout << "end.." << endl;
	system("pause");
	return 0;
}