/****************************************!
*@brief  ��������
*@author ZhangYunjia
*@date   2019/5/16/13:31

****************************************/


#include<iostream>

using namespace std;
//дn������������char���͡�int���͡�double���ͱ�����ֵ��

//�б�Ҫ�ú����Ĳ������Ͳ�����--����ģ�壨���ͱ�̣�
//tmplate����c++��������Ҫ��ʼ���ͱ���ˣ�����T��Ҫ��㱨��
template <typename T>
void my_swap(T &a, T &b) {
	cout << "ģ�庯��" << endl;
	T c;
	c = a;
	a = b;
	b = c;

}

void my_swap(int a, char c) {

	cout << "��ͨ����" << endl;
	cout << "a:" << a << endl << "c:" << c << endl;

}


int main()
{

	//���ͱ��-����ģ��ĵ��ã�1.��ʽ���͵��� 2.�Զ������Ƶ�

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

	cout << "******************************" << endl;
	{
		
		int x = 10;
		char y = 'z';
		my_swap(x, y);
		
		my_swap(y, x);//��ͨ�����ĵ��ã����Խ�����ʽ������ת��
		my_swap(x, x);//ģ�庯���ĵ��ã����ʣ����Ͳ����������ϸ������ͽ���ƥ�䣬��������Զ�����ת��

	}




	cout << "end.." << endl;
	system("pause");
	return 0;
}