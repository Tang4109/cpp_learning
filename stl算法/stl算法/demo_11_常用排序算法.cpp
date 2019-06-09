/****************************************!
*@brief  常用排序算法
*@author ZhangYunjia
*@date   2019/6/9/13:32

****************************************/

#include<iostream>
#include<iostream>
#include "iterator"
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;
//1.merge算法
void print(vector<int>& v)
{
	for (int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}

}
void merge_()
{
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(8);

	v3.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
}


//2.sort算法
class Student
{
public:
	Student(string name_, int id_) 
	{
		name = name_;
		id = id_;
	}
	void print_s()
	{
		cout << id << ":" << name << endl;

	}
public:
	string name;
	int id;
};
//谓词
bool compare(Student &s1, Student& s2)
{
	return (s1.id < s2.id);
}

void sort_()
{
	Student s1("zyj", 1);
	Student s2("xhh", 2);
	Student s3("ljh", 3);
	Student s4("zrf", 4);
	vector<Student> v1;
	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s2);
	v1.push_back(s3);
	
	for (int i=0;i<v1.size();i++)
	{
		v1[i].print_s();
	}

	sort(v1.begin(), v1.end(), compare);
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i].print_s();
	}

	string str = "kakajfhugnd";
	sort(str.begin(), str.end());
	cout << "str:" << str << endl;
}

//3.random_shuffle函数
void random_shuffle_()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(11);

	random_shuffle(v1.begin(), v1.end());
	print(v1);
	cout << endl;

	string str = "abcdefghijk";
	random_shuffle(str.begin(), str.end());
	cout << "str:" << str << endl;

}

//4.reverse函数
void reverse_()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(11);
	reverse(v1.begin(), v1.end());
	print(v1);
	cout << endl;

	string str = "abcdefghijk";
	reverse(str.begin(), str.end());
	cout << "str:" << str << endl;
}

int main()
{

	//merge_();
	//sort_();
	//random_shuffle_();
	reverse_();

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}