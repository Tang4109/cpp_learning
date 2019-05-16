/****************************************!
*@brief  ģ��������Ԫ����
*@author ZhangYunjia
*@date   2019/5/16/21:00

****************************************/

#include<iostream>

using namespace std;

template<typename T>
class complex
{
	//friend ostream& operator<<(ostream &out, complex &c3);
	friend ostream& operator<<(ostream &out, complex &c3) {
		out << "a:" << c3.a << endl << "b:" << c3.b << endl;
		return out;
	}

	friend complex my_sub(complex &c1, complex &c2) {
		complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}
	
public:
	complex(T a_, T b_) {
		a = a_;
		b = b_;
	}
	void print_com() {
		cout << "a:" << a << endl << "b:" << b << endl;
	}

	complex operator+(complex &c2) {
		complex tmp(a + c2.a, b + c2.b);
		return tmp;

	}

private:
	T a;
	T b;
};

//��������ص�����д��:<<>>ֻ������Ԫ������������������ض�Ҫд�ɳ�Ա��������Ҫ������Ԫ����

//ostream& operator<<(ostream &out, complex<int> &c3) {
//
//	out<< "a:" << c3.a << endl << "b:" << c3.b << endl;
//	return out;
//}


int main()
{

	complex<int>c1(1, 2);
	complex<int>c2(3, 4);

	//���������
	complex<int>c3 = c1 + c2;
	cout << c3 << endl;

	//������Ԫ����
	{
		complex<int>c4 = my_sub(c1, c2);
		cout << c4 << endl;


	}


	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}