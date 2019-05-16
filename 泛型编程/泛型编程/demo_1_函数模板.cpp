/****************************************!
*@brief  ����ģ��(tmplate)
*@author ZhangYunjia
*@date   2019/5/16/10:50

****************************************/

#include<iostream>

using namespace std;
//дn������������char���͡�int���͡�double���ͱ�����ֵ��
//�����Ĳ������Ͳ�ͬ
class swaps {
public:
	 void my_swap(int &a, int &b) {
		int c = 0;
		c = a;
		a = b;
		b = c;


	}

	void my_swap(char &a, char &b) {
		int c = 0;
		c = a;
		a = b;
		b = c;

	}


};


//�б�Ҫ�ú����Ĳ������Ͳ�����--����ģ�壨���ͱ�̣�
//tmplate����c++��������Ҫ��ʼ���ͱ���ˣ�����T��Ҫ��㱨��
template <typename T>

void my_swap(T &a,T &b) {
	T c;
	c = a;
	a = b;
	b = c;

}


int main()
{
	//ԭʼ��ʽ
	{
		swaps swaps_int;
		int x = 10;
		int y = 20;
		swaps_int.my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
	}
	{
		swaps swaps_char;
		char x = 'x';
		char y = 'y';
		swaps_char.my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
	}
	//���ͱ��-����ģ��ĵ��ã�1.��ʽ���͵��� 2.�Զ������Ƶ�

	cout << "******************************" << endl;
	{
		//1.��ʽ���͵���
		int x = 10;
		int y = 20;
		my_swap<int>(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
		//2.�Զ������Ƶ�
		my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;

	}

	{
		char x = 'x';
		char y = 'y';
		my_swap<char>(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
		//2.�Զ������Ƶ�
		my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;

	}


	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}