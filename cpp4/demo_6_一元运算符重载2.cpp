/****************************************!
*@brief  ����++�����--
*@author ZhangYunjia
*@date   2019/4/25/21:25

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
	//����--
	complex_operation operator--(int) {
		complex_operation tmp=*this;
		this->a--;
		this->b--;
		return tmp;
	}
	//ȫ�ֺ�������
	friend complex_operation operator++(complex_operation &c1,int);

};
/*
ȫ�ֺ��������Ա��������ʵ����������ز���
1��Ҫ���ϲ�����������һ��������д����������operator+ ()
2�����ݲ�������д����������
3������ҵ�����ƺ�������ֵ(�������Ƿ������� ����ָ�� Ԫ��)����ʵ�ֺ���ҵ��

*/

//����++
complex_operation operator++(complex_operation &c1,int) {
	
	complex_operation tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;
}


int main()
{

	complex_operation c1(1, 2), c2(3, 4);
	c1++;
	c1.print_comp();

	c1--;
	c1.print_comp();

	cout << "end.." << endl;
	system("pause");
	return 0;
}

