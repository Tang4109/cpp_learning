/****************************************!
*@brief  c��c++��ǿ������ת��
*@author ZhangYunjia
*@date   2019/5/18/11:12

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


int main()
{

	double pi = 3.1415926;
	int num1 = pi;//c��������ʽ����ת��
	int num2 = (int)pi;//c���Է��

	int num3 =static_cast<int>(pi);//c++��̬����ת����c��������ʽ����ת����������static_cast<int>()ת��
	cout << num3 << endl;
	

	char* p1;
	int* p2 = NULL;
	p1 = new char[4];
	strcpy(p1, "zyj");
	//p2 = p1;//err
	//p2 = static_cast<int>(p1);//err
	p2 = reinterpret_cast<int*>(p1);//ǿ������ת��
	cout << p1 << endl;
	cout << p2 << endl;

	delete[] p1;
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}