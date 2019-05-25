/****************************************!
*@brief  stack
*@author ZhangYunjia
*@date   2019/5/24/20:07

****************************************/

#include<iostream>
#include "stack"
using namespace std;

void stack_()
{
	stack<int> s;
	//»Î’ª
	for (int i=0;i<10;i++)
	{
		s.push(i);
	}
	//≥ˆ’ª
	while (!s.empty())
	{
		int tmp = s.top();
		cout << tmp << " ";
		s.pop();
	}
	


}
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
void stack_class()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t1.name="zyj";
	t2.name = "xhh";
	t3.name = "ljh";
	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);
	while (!s.empty())
	{
		Teacher tmp = s.top();
		tmp.print();
		s.pop();
	}

}
void stack_pointer()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t1.name = "zyj";
	t2.name = "xhh";
	t3.name = "ljh";
	stack<Teacher*> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);
	while (!s.empty())
	{
		Teacher* tmp = s.top();
		tmp->print();
		s.pop();
	}
}

int main()
{

	//stack_();
	//stack_class();
	stack_pointer();

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}