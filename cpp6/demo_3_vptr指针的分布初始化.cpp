/****************************************!
*@brief  当执行父类的构造函数时，子类的vptr指针指向父类的虚函数表，执行完毕之后再指向子类的虚函数表
*@author ZhangYunjia
*@date   2019/5/1/11:02

****************************************/

#include<iostream>

using namespace std;

class parent {
private:
	int a;
public:
	parent(int a_ = 0) {
		this->a = a_;
		print();//调用父类的print

	}
	//虚继承
	virtual void print() {
		cout << "parent " << a << endl;
	}

};

class child :public parent {
private:
	int b;
public:
	child(int a_ = 0, int b_ = 0) :parent(a_) {
		this->b = b_;
		print();
	}
	virtual void print() {
		cout << "child " << b << endl;
	}

};

void print(parent *base) {
	base->print();//多态
				  //迟绑定（虚函数表）
				  //动态链编与静态链编
}


int main()
{

	
	child c1;
	

	cout << "end.." << endl;
	system("pause");
	return 0;
}