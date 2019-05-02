/****************************************!
*@brief  ����������̣�����Ԥ�ȶ���õĽӿڱ�̣�-ģ�黮��
*@author ZhangYunjia
*@date   2019/5/2/10:24

****************************************/

#include<iostream>

using namespace std;

class abstract { //������
public:
	virtual void get_area() = 0;//���麯��
};

class circle :public abstract{
private:
	int r;

public:
	circle(int r_) {
		this->r = r_;
	}
	virtual void get_area() {
		cout << "Բ�������" << 3.14*r*r << endl;
	}

};

class triangle :public abstract{
private:
	int a;
	int b;

public:
	triangle(int a_, int b_) {
		this->a = a_;
		this->b = b_;

	}
	virtual void get_area() {
		cout << "�����ε������" << 0.5*a*b << endl;
	}

};

class square :public abstract{
private:
	int a;
	int b;

public:
	square(int a_, int b_) {
		this->a = a_;
		this->b = b_;

	}
	virtual void get_area() {
		cout << "�ı��ε������" << a*b << endl;
	}

};

void print(abstract &base) {
	base.get_area();//��̬
}


int main()
{
	//abstract a;//�����಻�ܱ�ʵ����
	
	abstract *base = NULL;//ok
	circle c1(10);
	print(c1); 

	triangle t1(20, 30);
	print(t1);

	square s1(50, 60);
	print(s1);


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}