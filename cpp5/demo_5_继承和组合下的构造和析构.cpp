/****************************************!
*@brief  继承和组合下的构造和析构
*@author ZhangYunjia
*@date   2019/4/28/14:47

****************************************/

#include<iostream>
#include <cstring>
using namespace std;

class grand_father {
protected:
	int a;
	int b;
public:
	grand_father(int a, int b) {
		this->a = a;
		this->b = b;
		cout << "grand_father 构造函数" << a << " " << b << endl;
	}
	~grand_father() 
	{
		cout << "grand_father 析构函数" << a << " " << b << endl;
	}

};

class parent:public grand_father
{
protected:
	const char *p;
public:
	void print_p() {
		cout << "f class" << endl;
	}
public:
	parent(const char *p, int _e, int _f):grand_father(_e, _f) {
		this->p = p;
		cout << "parent 构造函数" << p << endl;
	}
	~parent() {
		cout << "parent 析构函数" << p << endl;
	}
	//parent(const parent &obj) {
	//	cout << "parent copy 构造函数" << endl;
	//}
};

class child :public parent
{
public:
	void print_c() {
		cout << "c class" << endl;
	}
	child(const char *p_c,const char *p,int _e,int _f,int _a,int _b,int _c,int _d) :parent(p,_e,_f),g1(_a,_b),g2(_c,_d)
	{
		this->p_c = p_c;
		cout << "child 构造函数" << p_c << endl;
		
	}
	~child() {
		cout << "child 析构函数" << p_c << endl;
	}
protected:
	const char* p_c;
	grand_father g1;
	grand_father g2;

};

void operation() {
	//parent p(1, 2);
	
	child c("zrf","zyj",1,2,3,4,5,6);
}


int main()
{
	//1.
	operation();

	cout << "end.." << endl;
	system("pause");
	return 0;
}