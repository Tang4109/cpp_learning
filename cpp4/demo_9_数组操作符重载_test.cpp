/****************************************!
*@brief  数组操作符重载
*@author ZhangYunjia
*@date   2019/4/26/10:32

****************************************/
#include<iostream>
#include "demo_9_数组操作符重载.h"
using namespace std;


int main()
{

	Array a1(10);
	for (int i = 0; i<a1.length(); i++)
	{
		a1.set_data(i, i);
	}
	for (int i = 0; i<a1.length(); i++)
	{
		cout << a1.get_data(i) << endl;
	}

	Array a2 = a1;

	for (int i = 0; i<a2.length(); i++)
	{
		cout << a2.get_data(i) << endl;
	}
	cout << "******************************" << endl;
	
	for (int i = 0; i < a1.length(); i++)
	{
		a1[i] = i+10;

	}

	for (int i=0;i<a1.length();i++)
	{
		cout << a1[i] << endl;

	}
	cout << "END..." << endl;
	system("pause");
	return 0;
}
