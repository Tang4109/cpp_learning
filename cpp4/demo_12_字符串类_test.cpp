/****************************************!
*@brief  �ַ�����(�Ⱥ�/�����±�/����/˫�Ⱥ�/���Ⱥ�/С��/����/���� ���������)
*@author ZhangYunjia
*@date   2019/4/26/15:23

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "demo_12_�ַ�����.h"
using namespace std;


int main()
{
	my_string s1(0);
	s1.print();
	my_string s2("a");
	s2.print();
	//1.�Ⱥ�
	my_string s3 = "b";
	s3.print();

	//2.�����±�
	my_string s4 = "zyjzyjzyj";
	s4[0]='1';
	s4.print();
	//3.����
	printf("%c", s4[0]);
	cout << endl;
	cout << s4 << endl;

	//4.˫�Ⱥ�/���Ⱥ�

	if (s2=="zyj")
	{
		cout << "���" << endl;
	} 
	else
	{
		cout << "�����" << endl;

	}
	if (s2!=s3)
	{
		cout << "�����" << endl;
	}
	else
	{
		cout << "���" << endl;

	}
	//5.���ڣ�С��
	cout << "***********************************************************" << endl;
	if (s3<"c")
	{
		cout << "s3С��c" << endl;
	} 
	else
	{
		cout << "s3����c" << endl;
	}

	if (s3 > s2)
	{
		cout << "s3����s2" << endl;
	}
	else
	{
		cout << "s3С��s2" << endl;
	}
	cout << ("b" < "a") << endl;
	cout << ("b" < "c") << endl;
	cout << strcmp("b", "d") << endl;


	//6.�������˽������
	cout << "***********************************************************" << endl;
	my_string s5 = "aabb";
	cout << s5 << endl;
	strcpy(s5.c_str(), "ccdd");
	cout << s5 << endl;

	//7.����>>
	cout << "***********************************************************" << endl;
	my_string s6(128);
	cout << "please input string:" << endl;
	cin >> s6;
	cout << s6 << endl;

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}