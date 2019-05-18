/****************************************!
*@brief  c与c++的强制类型转换
*@author ZhangYunjia
*@date   2019/5/18/11:12

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


int main()
{

	double pi = 3.1415926;
	int num1 = pi;//c语言中隐式类型转换
	int num2 = (int)pi;//c语言风格

	int num3 =static_cast<int>(pi);//c++静态类型转换，c语言中隐式类型转换都可以用static_cast<int>()转换
	cout << num3 << endl;
	

	char* p1;
	int* p2 = NULL;
	p1 = new char[4];
	strcpy(p1, "zyj");
	//p2 = p1;//err
	//p2 = static_cast<int>(p1);//err
	p2 = reinterpret_cast<int*>(p1);//强制类型转换
	cout << p1 << endl;
	cout << p2 << endl;

	delete[] p1;
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}