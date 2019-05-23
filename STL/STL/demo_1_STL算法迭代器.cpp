/****************************************!
*@brief  容器vector与迭代器iterator
*@author ZhangYunjia
*@date   2019/5/23/14:46

****************************************/

#include<iostream>
#include "vector"
using namespace std;

//容器中装基础数据类型
void main_test() {
	//1容器，把你的元素copy到容器中
	vector<int> v1;
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(5);
	//2迭代器：相当于一个指针
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	//3算法:算法和迭代器进行无缝的连接
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
//容器中装类元素
void main_test2() {
	
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	//1容器，把你的元素copy到容器中,实现了数据类型和算法的有效分离
	vector<Teacher> v1;
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//2迭代器：相当于一个指针
	for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->age << " ";
	}

}
//容器中装指针
void main_test3() {

	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	//1容器，把你的元素copy到容器中,实现了数据类型和算法的有效分离
	vector<Teacher*> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//2迭代器：相当于一个指针
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