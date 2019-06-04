/****************************************!
*@brief  for_each和transform的区别
*@author ZhangYunjia
*@date   2019/6/4/13:45

****************************************/

#include<iostream>
#include "iterator"
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
int FuncShowElemt2(T t)
{
	cout << t << " ";
	return t;
}

int main()
{
	vector<int> v1;
	for (int i = 1; i < 6; i = i + 2)
	{
		v1.push_back(i);
	}

	for_each(v1.begin(), v1.end(), FuncShowElemt<int>);


	vector<int> v2 = v1;
	transform(v1.begin(), v1.end(), v2.begin(), FuncShowElemt2<int>);

	
	 
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}