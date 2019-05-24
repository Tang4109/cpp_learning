/****************************************!
*@brief  string
*@author ZhangYunjia
*@date   2019/5/24/8:56

****************************************/
#define _SCL_SECURE_NO_WARNINGS
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
	cout << endl;
	//3.
	try
	{
		for (int i = 0; i < s.length()+3; i++)
		{
			cout << s.at(i) << " ";//可以抛出异常
		}
	}
	catch (...)
	{
		cout << "发生异常" << endl;
	}


}

//字符指针和string类的转换
void string_transfer() {
	//1.char* -> string
	string s = "zyj";
	//2.string -> char*
	cout << s.c_str() << endl;
	printf("%s", s.c_str());
	cout << endl;
	//3.s的内容copy到buf中
	char buf[128] = { 0 };
	s.copy(buf,2,1);
	cout << buf << endl;

}
//字符串的连接
void string_connect() {
	string s1 = "zyjzyjzyzjyzj";
	string s2 = "11111233333";
	string s = s1 + s2;
	cout << s << endl;
	s.append(s1);
	cout << s << endl;

}

//字符串的查找和替换
void string_search() {
	string s = "hello zyj hello you are zyj  a big  zyj boy zyj.";
	//zyj 第一次出现的位置
	int index = s.find("zyj", 0);
	cout << index << endl;
	//zyj出现的次数及每一次出现的数组下标
	int num = 0;
	while (index!=string::npos)
	{
		num++;
		cout << "index:" << index << " ";
		s.replace(index, 3, "ZYJ");//替换
		index++;
		index = s.find("zyj", index);
	}
	cout << endl;
	cout << "num:" << num << endl;
	//替换
	cout << s << endl;

}

int main()
{
	
	string_init();
	string_traverse();
	cout << "*************************1" << endl;
	string_transfer();
	cout << "*************************2" << endl;
	string_connect();
	cout << "*************************3" << endl;
	string_search();

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}

