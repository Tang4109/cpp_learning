/****************************************!
*@brief  ջ����
*@author ZhangYunjia
*@date   2019/5/18/18:05

****************************************/

#include<iostream>

using namespace std;

class Test
{
public:
	Test(int a_, int b_) {
		a = a_;
		b = b_;
		cout << "���캯��" << endl;
	}

	~Test()
	{
		cout << "��������" << endl;
	}

private:
	int a;
	int b;
};



void divide(int x, int y)
{
	if (y == 0)
	{
		throw 'z';//�׳� int���͵��쳣

	}
	cout << "x/y=" << x / y << endl;
}

void my_divide()
{
	Test t1(1, 2);
	Test t2(3, 4);
	cout << "my_divide err" << endl;
	throw 1;
}


int main()
{
	try
	{
		//divide(10, 2);
		//divide(100, 0);
		my_divide();//�쳣�ǿ纯����
	}
	catch (int e)
	{
		cout << e << " err" << endl;

	}
	catch (...)//�ϸ������ͽ���ƥ��
	{
		cout << "δ֪�쳣" << endl;
	}



	cout << "end.." << endl;
	system("pause");
	return 0;
}