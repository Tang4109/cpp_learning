/****************************************!
*@brief  常用拷贝和替换算法
*@author ZhangYunjia
*@date   2019/6/9/14:33

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

void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}
//1.copy函数
void copy_()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	print(v2);

}
//2.replace函数
void replace_()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(3);

	replace(v1.begin(), v1.end(), 3, 8);
	print(v1);

}

//3.replace_if函数
bool greaters(int& k)
{
	if (k>=5)
	{
		return true;
	}
	return false;
}

void replace_if_()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(3);

	replace_if(v1.begin(), v1.end(),greaters,0);
	print(v1);


}
//3.swap函数
void sawp_()
{
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(8);

	swap(v1, v2);
	//swap(v1.begin(), v1.end(), v2.begin(),v2.end());

	print(v1);
	cout << endl;
	print(v2);

}
int main()
{
	//copy_();
	//replace_();
	//replace_if_();
	sawp_();

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}