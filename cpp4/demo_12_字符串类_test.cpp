/****************************************!
*@brief  字符串类(等号/数组下标/左移/双等号/不等号/小于/大于/输入 运算符重载)
*@author ZhangYunjia
*@date   2019/4/26/15:23

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "demo_12_字符串类.h"
using namespace std;


int main()
{
	my_string s1(0);
	s1.print();
	my_string s2("a");
	s2.print();
	//1.等号
	my_string s3 = "b";
	s3.print();

	//2.数组下标
	my_string s4 = "zyjzyjzyj";
	s4[0]='1';
	s4.print();
	//3.左移
	printf("%c", s4[0]);
	cout << endl;
	cout << s4 << endl;

	//4.双等号/不等号

	if (s2=="zyj")
	{
		cout << "相等" << endl;
	} 
	else
	{
		cout << "不相等" << endl;

	}
	if (s2!=s3)
	{
		cout << "不相等" << endl;
	}
	else
	{
		cout << "相等" << endl;

	}
	//5.大于，小于
	cout << "***********************************************************" << endl;
	if (s3<"c")
	{
		cout << "s3小于c" << endl;
	} 
	else
	{
		cout << "s3大于c" << endl;
	}

	if (s3 > s2)
	{
		cout << "s3大于s2" << endl;
	}
	else
	{
		cout << "s3小于s2" << endl;
	}
	cout << ("b" < "a") << endl;
	cout << ("b" < "c") << endl;
	cout << strcmp("b", "d") << endl;


	//6.访问类的私有属性
	cout << "***********************************************************" << endl;
	my_string s5 = "aabb";
	cout << s5 << endl;
	strcpy(s5.c_str(), "ccdd");
	cout << s5 << endl;

	//7.重载>>
	cout << "***********************************************************" << endl;
	my_string s6(128);
	cout << "please input string:" << endl;
	cin >> s6;
	cout << s6 << endl;

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}