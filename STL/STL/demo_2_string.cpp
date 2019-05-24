/****************************************!
*@brief  string
*@author ZhangYunjia
*@date   2019/5/24/8:56

****************************************/

#include<iostream>
#include "string"
using namespace std;

//string类的初始化
void string_init() {
	string s1 = "aaaa";
	string s2("bbbb");
	string s3 = s2;//通过copy构造函数来初始化对象s3
	string s4(10, 'a');
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}
//string的遍历
void string_traverse() {
	//1.数组方式
	string s = "abcdefg";
	for (int i=0;i<s.length();i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	//2.迭代器
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