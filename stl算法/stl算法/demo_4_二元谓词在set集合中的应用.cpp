/****************************************!
*@brief  二元谓词在set集合中的应用
*@author ZhangYunjia
*@date   2019/6/2/22:54

****************************************/

#include<iostream>
#include "vector"
#include "algorithm"
#include "set"
#include <string>
using namespace std;


//二元函数对象
template<typename T>
class sumAdd
{
public:
	T operator() (T t1, T t2)
	{
		return t1 + t2;
	}
protected:
private:

};
//二元函数
void two_function()
{ 
	vector<int> v1, v2;
	vector<int> v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), sumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << endl;
	}

}

template <typename T>
void FuncShowElemt(T &t)
{
	cout << t << " ";
}

bool myCompare(const int& a, const int& b)
{
	return a < b;//从小到大排序

}
//二元谓词
void two_element()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		v[i] = tmp;
	}
	//两种遍历的方法
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for_each(v.begin(), v.end(), FuncShowElemt<int>);
	//算法和容器通过迭代器进行无缝连接
	//排序
	sort(v.begin(), v.end(), myCompare);
	cout << endl;
	for_each(v.begin(), v.end(), FuncShowElemt<int>);
}

struct compareNoCase
{
	bool operator()(const string& str1, const string& str2) const
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);//tolower-预定义函数对象
		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);//tolower-预定义函数对象

		return (str1_ < str2_);

	}

};


void set_()
{
	//set<string> set1;
	//set1.insert("bbb");
	//set1.insert("aaa");
	//set1.insert("ccc");
	//set<string>::iterator it = set1.find("Aaa");//find 默认区分大小写
	//if (it!=set1.end())
	//{
	//	cout << "查找到aaa" << endl;
	//}
	//else
	//{
	//	cout << "没有查找到aaa" << endl;

	//}

	set<string, compareNoCase> set2;
	set2.insert("aaa");
	set2.insert("bbb");
	set2.insert("ccc");

	set<string>::iterator it2 = set2.find("Aaa");//find 默认区分大小写
	if (it2 != set2.end())
	{
		cout << "查找到aaa" << endl;
	}
	else
	{
		cout << "没有查找到aaa" << endl;

	}

}


int main()
{




	set_();

	cout << "\nend.." << endl;
	system("pause");
	return 0;
}