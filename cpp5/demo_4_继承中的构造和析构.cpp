/****************************************!
*@brief  �̳��еĹ��������
*@author ZhangYunjia
*@date   2019/4/28/14:27

****************************************/

#include<iostream>

using namespace std;

class parent
{

private:
	int a;
	int b;

public:
	void print_p() {
		cout << "f class" << endl;
	}
public:
	parent(int a,int b) {
		this->a = a;
		this->b = b;
		cout << "parent ���캯��" << endl;
	}
	~parent() {
		cout << "parent ��������" << endl;
	}

	parent(const parent &obj) {
		cout << "parent copy ���캯��" << endl;
	}
};

class child :public parent
{
public:
	void print_c() {
		cout << "c class" << endl;
	}
	child(int a, int b,int c) :parent(a,b)
	{
		cout << "child ���캯��" << endl;
		this->c = c;
	}
	~child() {
		cout << "child ��������" << endl;
	}
private:
	int c;

};

void operation() {
	//parent p(1, 2);
	child c(3, 4, 5);
}


int main()
{
	//1.

	operation();


	cout << "end.." << endl;
	system("pause");
	return 0;
}