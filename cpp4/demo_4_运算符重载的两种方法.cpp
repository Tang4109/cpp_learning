/****************************************!
*@brief  ȫ�ֺ������������Ա��������
*@author ZhangYunjia
*@date   2019/4/25/20:24

****************************************/

#include<iostream>
using namespace std;


class complex_operation {

private:
	int a;
	int b;
public:
	complex_operation(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;

	}
	void print_comp() {

		cout << a << "+" << b << "i" << endl;
	}
	//���Ա��������
	complex_operation operator-(complex_operation &c2) {

		complex_operation tmp(this->a-c2.a, this->b-c2.b);
		return tmp;
		
	}
	//ȫ�ֺ�������
	friend complex_operation operator+(complex_operation &c1, complex_operation &c2);

};
/*
ȫ�ֺ��������Ա��������ʵ����������ز���
1��Ҫ���ϲ�����������һ��������д����������operator+ ()
2�����ݲ�������д����������
3������ҵ�����ƺ�������ֵ(�������Ƿ������� ����ָ�� Ԫ��)����ʵ�ֺ���ҵ��

*/

//ȫ�ֺ���
complex_operation operator+(complex_operation &c1, complex_operation &c2) {
	complex_operation tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}


int main()
{

	complex_operation c1(1, 2), c2(3, 4);
	complex_operation c3 = c1 + c2;
	c3.print_comp();

	complex_operation c4 = c1 - c2;
	c4.print_comp();

	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
