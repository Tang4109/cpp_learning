/****************************************!
*@brief  ǰ��++��ǰ��--
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
	complex_operation& operator--() {
		this->a--;
		this->b--;
		return *this;
	}
	//ȫ�ֺ�������
	friend complex_operation& operator++(complex_operation &c1);

};
/*
ȫ�ֺ��������Ա��������ʵ����������ز���
1��Ҫ���ϲ�����������һ��������д����������operator+ ()
2�����ݲ�������д����������
3������ҵ�����ƺ�������ֵ(�������Ƿ������� ����ָ�� Ԫ��)����ʵ�ֺ���ҵ��

*/

//ȫ�ֺ���
complex_operation& operator++(complex_operation &c1) {
	//complex_operation tmp(c1.a + 1, c1.b + 1);
	c1.a++;
	c1.b++;
	//return tmp;
	return c1;
}


int main()
{

	complex_operation c1(1, 2), c2(3, 4);
	++c1;
	c1.print_comp();

	--c2;
	c2.print_comp();

	cout << "end.." << endl;
	system("pause");
	return 0;
}

