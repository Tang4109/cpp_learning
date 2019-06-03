/****************************************!
*@brief  for_each
*@author ZhangYunjia
*@date   2019/6/3/21:15

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
		cout << "���ô���:" << num << endl;
	}
protected:
private:
	T num;
};


void print1(vector<int>& v)
{
	for_each(v.begin(), v.end(), FuncShowElemt<int>);//�ص�����
	cout << endl;
	for_each(v.begin(), v.end(), showElemt<int>());//�ຯ������
	//for_each���غ�������
	cout << endl;
	showElemt<int> show2;
	showElemt<int> show1 = for_each(v.begin(), v.end(), show2);//�ຯ������/��ʼ��
	show1.print_num();//3
	show2.print_num();//0

	show1 = for_each(v.begin(), v.end(), show2);//��ֵ
	show1.print_num();

}

void print2(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)//������
	{
		cout << *it << " ";
	}
}

int main()
{
	vector<int> v1;
	for (int i=1;i<6;i=i+2)
	{
		v1.push_back(i);
	}

	print1(v1);
	cout << endl;
	print2(v1);
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}