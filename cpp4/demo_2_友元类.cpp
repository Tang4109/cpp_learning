/****************************************!
*@brief  ��Ԫ��
*@author ZhangYunjia
*@date   2019/4/25/16:33

****************************************/

#include<iostream>
using namespace std;


class A {
private:
	int a;
	int b;

public:
	/*
	��B����A�����Ա�࣬��B������г�Ա��������A�����Ա����
	��Ա��ͨ�����Ϊһ�ֶ����ݲ�������֮�䴫����Ϣ�ĸ�����
	*/

	friend class B;

	A(int a=0, int b=0) {
		this->a = a;
		this->b = b;

	}
	int get_A() {

		return this->a;
	}
	void print_A() {
		cout << this->a << endl;
		cout << this->b << endl;
	}

};

class B {
private:
	A object_a;
public:
	void set_A(int a,int b) {

		object_a.a = a;
		object_a.b = b;
	}
	void print_A() {
		cout << object_a.a << endl;
		cout << object_a.b << endl;

	}

};

int main()
{
	B b1;
	b1.set_A(10, 20);
	b1.print_A();
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
