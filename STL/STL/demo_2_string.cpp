/****************************************!
*@brief  string
*@author ZhangYunjia
*@date   2019/5/24/8:56

****************************************/
#define _SCL_SECURE_NO_WARNINGS
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
	cout << endl;
	//3.
	try
	{
		for (int i = 0; i < s.length()+3; i++)
		{
			cout << s.at(i) << " ";//�����׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣" << endl;
	}


}

//�ַ�ָ���string���ת��
void string_transfer() {
	//1.char* -> string
	string s = "zyj";
	//2.string -> char*
	cout << s.c_str() << endl;
	printf("%s", s.c_str());
	cout << endl;
	//3.s������copy��buf��
	char buf[128] = { 0 };
	s.copy(buf,2,1);
	cout << buf << endl;

}
//�ַ���������
void string_connect() {
	string s1 = "zyjzyjzyzjyzj";
	string s2 = "11111233333";
	string s = s1 + s2;
	cout << s << endl;
	s.append(s1);
	cout << s << endl;

}

//�ַ����Ĳ��Һ��滻
void string_search() {
	string s = "hello zyj hello you are zyj  a big  zyj boy zyj.";
	//zyj ��һ�γ��ֵ�λ��
	int index = s.find("zyj", 0);
	cout << index << endl;
	//zyj���ֵĴ�����ÿһ�γ��ֵ������±�
	int num = 0;
	while (index!=string::npos)
	{
		num++;
		cout << "index:" << index << " ";
		s.replace(index, 3, "ZYJ");//�滻
		index++;
		index = s.find("zyj", index);
	}
	cout << endl;
	cout << "num:" << num << endl;
	//�滻
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

