/****************************************!
*@brief  ��̬�Ļ���
*@author ZhangYunjia
*@date   2019/5/1/10:23

****************************************/

#include<iostream>

using namespace std;

class parent {
private:
	int a;
public:
	parent(int a_=0) {
		this->a = a_;

	}
	//��̳�
	virtual void print() {
		cout << "parent "<< a << endl;
	}

};

class child:public parent {
private:
	int b;
public:
	child(int a_=0,int b_=0):parent(a_) {
		this->b = b_;

	}
	virtual void print() {
		cout << "child "<< b << endl;
	}

};
 
void print(parent *base) {
	base->print();//��̬
	//�ٰ󶨣��麯����
	//��̬�����뾲̬����
}


int main()
{

	parent p1;//c++���������vptrָ�루��ǰ���֣�
	child c1;
	print(&p1);
	print(&c1);

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}