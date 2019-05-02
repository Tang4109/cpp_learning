/****************************************!
*@brief  通过父类指针析构所有的子类资源
*@author ZhangYunjia
*@date   2019/4/30/20:33

****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class A{
private:
	char *p;

public:
	A() {
		p = new char[20];
		strcpy(p, "zyj");
		cout << "A 构造函数" << endl;
	}
	virtual ~A() {
		delete[] p;
		cout << "A 析构函数" << endl;
	}

};

class B:public A {
private:
	char *p;

public:
	B() {
		p = new char[20];
		strcpy(p, "zrf");
		cout << "B 构造函数" << endl;
	}
	virtual ~B() {
		delete[] p;
		cout << "B 析构函数" << endl;

	}

};

class C :public B {
private:
	char *p;

public:
	C() {
		p = new char[20];
		strcpy(p, "ljh");
		cout << "C 构造函数" << endl;
	}
	virtual ~C() {
		delete[] p;
		cout << "C 析构函数" << endl;

	}

};

void deletes(A* base) {
	delete base;

}
void main_test() {
	C *my_c = new C;
	deletes(my_c);
}


int main()
{

	//main_test();
	C *my_c = new C;

	//1.
	//delete my_c;//直接通过子类对象释放资源
	
	//2.
	deletes(my_c);//通过父类指针释放子类的资源


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}