/****************************************!
*@brief  queue
*@author ZhangYunjia
*@date   2019/5/25/8:48

****************************************/

#include<iostream>
#include "queue"
using namespace std;

class Teacher
{
public:
	int age;
	const char* name;

public:
	void print()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;

	}
};

//queue�Ƚ��ȳ�
void queue_()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "��ͷԪ��:" << q.front() << endl;
	cout << "���еĴ�С:" << q.size() << endl;
	while (!q.empty())
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();

	}

}
//��Ԫ��
void queue_class()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t1.name = "zyj";
	t2.name = "xhh";
	t3.name = "ljh";
	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);
	while (!q.empty())
	{
		Teacher tmp = q.front();
		tmp.print();
		q.pop();
	}
}
//ָ��
void queue_pionter()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t1.name = "zyj";
	t2.name = "xhh";
	t3.name = "ljh";
	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);
	while (!q.empty())
	{
		Teacher* tmp = q.front();
		tmp->print();
		q.pop();
	}

}
int main()
{

	//queue_();
	//queue_class();
	queue_pionter();
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}