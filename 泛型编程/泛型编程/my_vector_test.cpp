/****************************************!
*@brief  数组模板类框架
*@author ZhangYunjia
*@date   2019/5/17/10:10

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "my_vector.cpp"
using namespace std;


int main_int()
{
	my_vector<int> my_v1(10);
	int len = my_v1.get_len();
	for (int i = 0;i< len;i++)
	{
		my_v1[i] = i;
		cout << my_v1[i] << " ";
	}
	cout << endl;
	my_vector<int>my_v2 = my_v1;
	
	for (int i = 0; i < len; i++)
	{
		cout << my_v2[i] << " ";
	}

	my_vector<int>my_v3;
	my_v3 = my_v1;

	//重载左移运算符
	cout << my_v3 << endl;

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}

int main_char()
{
	my_vector<char> my_v1(5);
	my_v1[0] = 'a';
	my_v1[1] = 'b';
	my_v1[2] = 'c';
	my_v1[3] = 'd';
	my_v1[4] = 'e';
	cout << my_v1 << endl;


	cout << "\nend.." << endl;
	system("pause");
	return 0;
}

class Teacher
{
private:
	int age;
	char name[32];
public:
	Teacher()
	{
		age = 33;
		strcpy(name, "");
	}
	Teacher(int age_, const char* name_)
	{
		age = age_;
		strcpy(name, name_);
	}
	void print_T()
	{
		cout << name << endl;
		cout << age << endl;
	}
};

int main()
{
	Teacher t1(31, "t1"), t2(32, "t2"), t3(33, "t3"), t4(34, "t4");
	my_vector<Teacher> my_v1(4);
	my_v1[0] = t1;
	my_v1[1] = t2;
	my_v1[2] = t3;
	my_v1[3] = t4;

	for (int i = 0; i < 4; i++)
	{
		Teacher tmp = my_v1[i];
		tmp.print_T();

	}

	cout << "\nend.." << endl;
	system("pause");
	return 0;
}