/****************************************!
*@brief  ����vector�������iterator
*@author ZhangYunjia
*@date   2019/5/23/14:46

****************************************/

#include<iostream>
#include "vector"
using namespace std;

//������װ������������
void main_test() {
	//1�����������Ԫ��copy��������
	vector<int> v1;
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(5);
	//2���������൱��һ��ָ��
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	//3�㷨:�㷨�͵����������޷������
	int num = count(v1.begin(), v1.end(), 3);
	cout << endl;
	cout << num << endl;
}

class Teacher
{
public:
	void prints() {
		cout << age << endl;
	}

public:
	int age;
	char name[24];
};
//������װ��Ԫ��
void main_test2() {
	
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	//1�����������Ԫ��copy��������,ʵ�����������ͺ��㷨����Ч����
	vector<Teacher> v1;
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//2���������൱��һ��ָ��
	for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->age << " ";
	}

}
//������װָ��
void main_test3() {

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	//1�����������Ԫ��copy��������,ʵ�����������ͺ��㷨����Ч����
	vector<Teacher*> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//2���������൱��һ��ָ��
	for (vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it)->age << " ";
	}

}


int main()
{

	main_test3();
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}