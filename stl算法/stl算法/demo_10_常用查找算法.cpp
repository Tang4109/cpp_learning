/****************************************!
*@brief  常用查找算法
*@author ZhangYunjia
*@date   2019/6/4/14:56

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


//查找第一个连续重复的位置
void adjacentFind(vector<int>& v1)
{
	//1.返回第一个连续重复的位置
	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	//位置
	int index = distance(v1.begin(), it);
	cout << index << endl;

}

//二分法查找：1024个数最多查找10次
void binarySearch(vector<int>& v1)
{
	bool b = binary_search(v1.begin(), v1.end(), 3);
	if (b==true)
	{
		cout << "Got it." << endl;
	}
	else
	{
		cout << "Not found." << endl;
	}

}
//计数
void counts(vector<int>& v1)
{
	int num = count(v1.begin(), v1.end(), 3);
	cout << num << endl;
}

bool greater_three(int num)
{
	if (num > 3)
	{
		return true;
	}
	return false;
}

void counts_if(vector<int>& v1)
{
	int num = count_if(v1.begin(), v1.end(), greater_three);
	cout << num << endl;
}

void finds(vector<int>& v1)
{
	vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
	cout << "*it:" << *it << endl;

	vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), greater_three);
	cout << "*it2:" << *it2 << endl;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(7);
	adjacentFind(v1);
	binarySearch(v1);
	counts(v1);
	cout << "***" << endl;
	counts_if(v1);
	cout << "***" << endl;
	finds(v1);

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}