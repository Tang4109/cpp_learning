/****************************************!
*@brief  一个调用语句有多种表现形态
*@author ZhangYunjia
*@date   2019/4/30/9:00

****************************************/

#include<iostream>

using namespace std;

class parent {
private:
	int a;
public:
	parent(int a_) {
		this->a = a_;
		cout << a << endl;

	}
public:
	virtual void print() {
		cout << "parent" << a << endl;
	}

};

class child:public parent{
private:
	int b;
public:
	child(int a_,int b_) :parent(a_)
	{
		this->b = b_;
		cout << b << endl;
	}
public:
	virtual void print() {
		cout << "child" << b << endl;
	}

};

void print1(parent *base) {
	base->print();
}

void print2(parent &base) {
	base.print();
}


int main()
{
	//1.指针
	
		parent *base = NULL;
		parent p1(20);
		child c1(10, 30);
		base = &p1;
		base->print();

		base = &c1;
		base->print();

	

	//2.引用
	{
		parent &base2 = p1;
		base2.print();

		parent &base3 = c1;
		base3.print();

	}

	//3.函数调用
	cout << "********************" << endl;
	print1(&p1);
	print1(&c1);

	print2(p1);
	print2(c1);

	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}