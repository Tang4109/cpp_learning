/****************************************!
*@brief  ���������������ֻ��ʹ����Ԫ��������
*@author ZhangYunjia
*@date   2019/4/26/8:52

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

	//��Ԫ��������
	friend ostream& operator<<(ostream &out, complex_operation &c1);

};

ostream& operator<<(ostream &out, complex_operation &c1) {
	out << "This is a test." << endl;
	out << c1.a << " + " << c1.b << "i" << endl;
	return out;//f֧����ʽ���
}

int main()
{

	int a = 10;
	complex_operation c1(1, 2), c2(3, 4);
	cout << a << endl;


	cout << c1;

	//��������ֵ����ֵ����Ҫ����һ������
	cout << c1<<"zyj"<<endl;
	
	

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}



