/****************************************!
*@brief  ���ͼ�����ԭ��
*@author ZhangYunjia
*@date   2019/4/28/10:45

****************************************/

#include<iostream>

using namespace std;

class parent
{

private:
	int a;

public:
	void print_p() {
		cout << "f class" << endl;
	}
public:
	parent() {
		cout << "parent ���캯��" << endl;
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
private:
	int c;

};

void print(parent *p) {
	p->print_p();
}

void print2(parent &p) {
	p.print_p();
}

int main()
{
	//1.
	parent p;
	child c;
	p.print_p();
	c.print_c();
	c.print_p();
	//2.����ָ��/����ָ���������
	cout << "***************" << endl;
	parent *p2 = NULL;
	p2 = &c;
	p2->print_p();
	//3.ָ��/��������������
	cout << "***************" << endl;
	print(&p);
	print(&c);
	print2(p);
	print2(c);
	//4.
	parent p3 = c;

	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}