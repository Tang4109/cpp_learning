/****************************************!
*@brief  set
*@author ZhangYunjia
*@date   2019/5/26/18:24

****************************************/
#include<iostream>
#include "set"
#include <functional>
using namespace std;

void print(set<int, greater<int>>& s)
{
	for (set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void set_()
{
	//元素唯一，自动从小到大排序
	//set<int> s;
	//set<int,less<int>> s;
	set<int, greater<int>> s;

	for (int i=0;i<5;i++)
	{
		int tmp = rand();
		s.insert(tmp);
	}
	//插入元素
	s.insert(100);//只插入一个100
	s.insert(100);
	s.insert(100);
	print(s);
	//删除
	while (!s.empty())
	{
		set<int>::iterator it = s.begin();
		cout << *it << " ";
		s.erase(s.begin());

	}
	print(s);


}
//自定义数据类型的比较
class Student
{
public:
	Student(const char* name,int age)
	{
		this->name = name;
		this->age = age;

	}
public:
	const char* name;
	int age;
};
//仿函数
struct  Func_Student
{
	bool operator()(const Student& left, const Student& right)
	{
		if (left.age<right.age)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

}; 

void prints(set<Student, Func_Student>& s)
{
	for (set<Student, Func_Student>::iterator it=s.begin();it!=s.end();it++)
	{
		cout << it->name<< " " << it->age << endl;
	}

}

void set_imitating()
{
	set<Student,Func_Student> s;
	Student s1("s1", 31);
	Student s2("s2", 35);
	Student s3("s3", 78);
	Student s4("s4", 26);
	Student s5("s5", 31);

	s.insert(s1);
	s.insert(s2);
	s.insert(s3);
	s.insert(s4);


	pair<set<Student, Func_Student>::iterator, bool> pair5 = s.insert(s5);
	if (pair5.second==true)
	{
		cout << "s5插入成功" << endl;
	}
	else
	{
		cout << "s5插入失败" << endl;
	}
	
	//遍历
	prints(s);

}
void printx(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
void set_find_pair()
{
	set<int> s;
	s.insert(4);
	for (int i = 0; i < 10; i++)
	{
		s.insert(rand());
		
	}
	printx(s);

	set<int>::iterator it_=s.find(4);
	cout << *it_ << endl;

	int num = s.count(4);
	cout << num << endl;
	
}

int main()
{

	//set_();
	//set_imitating();
	set_find_pair();

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}