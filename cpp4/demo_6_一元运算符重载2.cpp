/****************************************!
*@brief  后置++与后置--
*@author ZhangYunjia
*@date   2019/4/25/21:25

****************************************/

#include<iostream>
using namespace std;


class complex_operation {

private:
	int a;
	int b;
public:
	complex_operation(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;

	}
	void print_comp() {

		cout << a << "+" << b << "i" << endl;
	}
	//后置--
	complex_operation operator--(int) {
		complex_operation tmp=*this;
		this->a--;
		this->b--;
		return tmp;
	}
	//全局函数重载
	friend complex_operation operator++(complex_operation &c1,int);

};
/*
全局函数、类成员函数方法实现运算符重载步骤
1）要承认操作符重载是一个函数，写出函数名称operator+ ()
2）根据操作数，写出函数参数
3）根据业务，完善函数返回值(看函数是返回引用 还是指针 元素)，及实现函数业务

*/

//后置++
complex_operation operator++(complex_operation &c1,int) {
	
	complex_operation tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;
}


int main()
{

	complex_operation c1(1, 2), c2(3, 4);
	c1++;
	c1.print_comp();

	c1--;
	c1.print_comp();

	cout << "end.." << endl;
	system("pause");
	return 0;
}

