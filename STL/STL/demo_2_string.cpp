/****************************************!
*@brief  string
*@author ZhangYunjia
*@date   2019/5/24/8:56

****************************************/

#include<iostream>
#include "string"
using namespace std;

//string��ĳ�ʼ��
void string_init() {
	string s1 = "aaaa";
	string s2("bbbb");
	string s3 = s2;//ͨ��copy���캯������ʼ������s3
	string s4(10, 'a');
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}
//string�ı���
void string_traverse() {
	//1.���鷽ʽ
	string s = "abcdefg";
	for (int i=0;i<s.length();i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	//2.������
	for (string::iterator it=s.begin();it!=s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << &it << " ";
	}
}

int main()
{

	string_init();
	string_traverse();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}