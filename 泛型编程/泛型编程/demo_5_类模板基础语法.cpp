/****************************************!
*@brief  类模板派生
*@author ZhangYunjia
*@date   2019/5/16/15:55

****************************************/

#include<iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(T a_){
		a = a_;
	}
public:
	void print_A() {
		cout << "a:" << a << endl;
	}

private:
	T a;


};

//类模板做函数参数
void use_A(A<int> &a) {
	a.print_A();
}

int main51()
{
	A<int> a1(10);
	a1.print_A();
	use_A(a1);
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}

//类模板派生普通类
//数据类型确定才能分配内存
class B:public A<int>
{
public:
	B(int a_ = 10, int b_ = 20) :A<int>(a_) {
		b = b_;
	}
public:
	void print_B() {
		cout << "b:" << b << endl;
	}
protected:
private:
	int b;
};

int main52()
{
	B b1(1,2);
	b1.print_A();
	b1.print_B();
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}


//类模板派生模板类
template<typename T>
class C:public A<T>
{
public:
	C(T a_, T c_) :A<T>(a_) {
		c = c_;
	}
	void print_C() {
		cout << "c:" << c << endl;
	}
protected:
private:
	T c;
};


int main()
{
	C<int> c1(3,4);
	c1.print_A();
	c1.print_C();

	cout << "end.." << endl;
	system("pause");
	return 0;
}