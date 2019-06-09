/****************************************!
*@brief  常用集合算法
*@author ZhangYunjia
*@date   2019/6/9/15:19

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
#include<numeric>

using namespace std;

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}

void set_union_()
{
	vector<int> v1,v2,v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(v1.size() + v2.size());
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
}

int main()
{
	set_union_();
	
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}