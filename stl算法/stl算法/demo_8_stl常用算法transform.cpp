/****************************************!
*@brief  transform
*@author ZhangYunjia
*@date   2019/6/3/22:57

****************************************/


#include<iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

template<typename T>
void FuncShowElemt(T &t)
{
	cout << t << " ";
}

template<typename T>
class showElemt
{
public:
	showElemt()
	{
		num = 0;
	}
	void operator()(T& t)
	{
		num++;
		cout << t << " ";
	}
	void print_num()
	{
		cout << "调用次数:" << num << endl;
	}
protected:
private:
	T num;
};


void print1(vector<int>& v)
{
	for_each(v.begin(), v.end(), FuncShowElemt<int>);//回调函数
	cout << endl;
	for_each(v.begin(), v.end(), showElemt<int>());//类函数对象
												   //for_each返回函数对象
	cout << endl;
	showElemt<int> show2;
	showElemt<int> show1 = for_each(v.begin(), v.end(), show2);//类函数对象/初始化
	show1.print_num();//3
	show2.print_num();//0

	show1 = for_each(v.begin(), v.end(), show2);//赋值
	show1.print_num();

}

void print2(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)//迭代器
	{
		cout << *it << " ";
	}
}

void print_list(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)//迭代器
	{
		cout << *it << " ";
	}
}

int increase(int i)
{
	return i + 100;
}

int main()
{
	vector<int> v1;
	for (int i = 1; i < 6; i = i + 2)
	{
		v1.push_back(i);
	}
	//回调函数
	transform(v1.begin(), v1.end(), v1.begin(), increase);//回调函数
	print2(v1);
	//预定义函数对象
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());//回调函数
	cout << endl;
	print2(v1);

	//函数适配器
	list<int> my_list;
	my_list.resize(v1.size());
	transform(v1.begin(), v1.end(), my_list.begin(), bind2nd(multiplies<int>(),10));//回调函数
	cout << endl;
	print_list(my_list);



	cout << "\nend.." << endl;
	system("pause");
	return 0;
}