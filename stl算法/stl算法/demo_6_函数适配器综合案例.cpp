/****************************************!
*@brief  函数适配器综合案例
*@author ZhangYunjia
*@date   2019/6/3/20:23

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

class  isGreater
{
public:
	isGreater(int i)
	{
		m_num = i;
	}

	bool operator()(int& num)
	{
		if (num>m_num)
		{
			return true;
		}
		return false;
	}

private:
	int m_num;
};

int main()
{
	vector<int> v1;
	for (int i=0;i<10;i++)
	{
		v1.push_back(i + 1);
	}
	for_each(v1.begin(), v1.end(), FuncShowElemt<int>);
	int num = count(v1.begin(), v1.end(), 3);
	cout << endl;
	cout << "num:" << num << endl;
	//通过谓词求大于2的个数
	int num1 = count_if(v1.begin(), v1.end(), isGreater(2));
	cout << "num1:" << num1 << endl;
	//通过预定义函数对象求大于2的个数
	int num2 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),4) );
	cout << "num2:" << num2 << endl;
	
	//通过预定义函数对象求奇数的个数
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "奇数的个数num3:" << num3 << endl;

	//通过预定义函数对象求偶数的个数
	int num4 = count_if(v1.begin(), v1.end(), not1( bind2nd(modulus<int>(), 2) ) );
	cout << "偶数的个数num4:" << num4 << endl;
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}