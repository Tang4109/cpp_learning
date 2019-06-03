/****************************************!
*@brief  �����������ۺϰ���
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
	//ͨ��ν�������2�ĸ���
	int num1 = count_if(v1.begin(), v1.end(), isGreater(2));
	cout << "num1:" << num1 << endl;
	//ͨ��Ԥ���庯�����������2�ĸ���
	int num2 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),4) );
	cout << "num2:" << num2 << endl;
	
	//ͨ��Ԥ���庯�������������ĸ���
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "�����ĸ���num3:" << num3 << endl;

	//ͨ��Ԥ���庯��������ż���ĸ���
	int num4 = count_if(v1.begin(), v1.end(), not1( bind2nd(modulus<int>(), 2) ) );
	cout << "ż���ĸ���num4:" << num4 << endl;
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}