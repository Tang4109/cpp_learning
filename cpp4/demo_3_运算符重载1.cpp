/****************************************!
*@brief  运算符重载入门技术推演
*@author ZhangYunjia
*@date   2019/4/25/17:12

****************************************/

#include<iostream>
using namespace std;


class complex_operation {

public:
	int a;
	int b;
public:
	complex_operation(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;

	}
	void print_comp() {

		cout << a << "+" << b << "i";
	}


};
//全局函数
complex_operation my_add(complex_operation &c1, complex_operation &c2) {
	complex_operation tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

//函数名升级
complex_operation operator+(complex_operation &c1, complex_operation &c2) {
	complex_operation tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

int main()
{

	int a = 0, b = 0;
	int c;
	c = a + b;

	complex_operation c1(1,2), c2(3,4);
	complex_operation c3;
	//c3 = c1 + c2;
	c3 = my_add(c1, c2);
	c1.print_comp();
	cout << " + ";
	c2.print_comp();
	cout << " = ";
	c3.print_comp();
	//////////////////////////////////////////////////////////////////////////
	cout << endl;
	complex_operation c4 = operator+(c1, c2);
	c4.print_comp();

	//////////////////////////////////////////////////////////////////////////
	cout << endl;
	complex_operation c5 = c1+c2;
	c5.print_comp();


	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}
