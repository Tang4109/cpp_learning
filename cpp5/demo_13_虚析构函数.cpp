/****************************************!
*@brief  ͨ������ָ���������е�������Դ
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
		cout << "A ���캯��" << endl;
	}
	virtual ~A() {
		delete[] p;
		cout << "A ��������" << endl;
	}

};

class B:public A {
private:
	char *p;

public:
	B() {
		p = new char[20];
		strcpy(p, "zrf");
		cout << "B ���캯��" << endl;
	}
	virtual ~B() {
		delete[] p;
		cout << "B ��������" << endl;

	}

};

class C :public B {
private:
	char *p;

public:
	C() {
		p = new char[20];
		strcpy(p, "ljh");
		cout << "C ���캯��" << endl;
	}
	virtual ~C() {
		delete[] p;
		cout << "C ��������" << endl;

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
	//delete my_c;//ֱ��ͨ����������ͷ���Դ
	
	//2.
	deletes(my_c);//ͨ������ָ���ͷ��������Դ


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}