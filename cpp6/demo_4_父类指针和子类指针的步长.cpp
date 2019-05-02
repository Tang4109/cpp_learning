/****************************************!
*@brief  子类和父类指针的步长不一样，多态是用父类指针指向子类对象
*@author ZhangYunjia
*@date   2019/5/2/9:47

****************************************/

#include<iostream>

using namespace std;

class parent {
private:
	int a;
public:
	parent(int a_ = 0) {
		this->a = a_;
		//print();//调用父类的print

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
		//print();
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
	child *c = NULL;
	parent *p = NULL;

	child array[] = { child(1),child(2),child(3) };
	p = array;
	c = array;
	cout << "***************" << endl;
	//p->print();
	c->print();

	//p++;
	c++;
	//p->print();
	c->print();

	//p++;
	c++;
	//p->print();
	c->print();



	cout << "end.." << endl;
	system("pause");
	return 0;
}