/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/6/9/15:09

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
	for (int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}

}



//1.accumulateº¯Êý
void accumulate_()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);


	int num = accumulate(v1.begin(), v1.end(), 100);
	cout << num << endl;

}

//2.fillº¯Êý
void fill_()
{
	vector<int> v1(8);
	//v1.push_back(1);
	//v1.push_back(3);
	//v1.push_back(5);
	//v1.resize(5);

	fill(v1.begin(), v1.end(), 100);
	print(v1);

}

int main()
{
	//accumulate_();
	fill_();
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}