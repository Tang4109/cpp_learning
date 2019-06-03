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

void print_list(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)//������
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
	//�ص�����
	transform(v1.begin(), v1.end(), v1.begin(), increase);//�ص�����
	print2(v1);
	//Ԥ���庯������
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());//�ص�����
	cout << endl;
	print2(v1);

	//����������
	list<int> my_list;
	my_list.resize(v1.size());
	transform(v1.begin(), v1.end(), my_list.begin(), bind2nd(multiplies<int>(),10));//�ص�����
	cout << endl;
	print_list(my_list);



	cout << "\nend.." << endl;
	system("pause");
	return 0;
}