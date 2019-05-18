/****************************************!
*@brief 运行时类型识别
*@author ZhangYunjia
*@date   2019/5/18/11:12

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Animal
{
public:
	virtual void cry() = 0;

};

class Dog:public Animal
{
public:
	virtual void cry()
	{
		cout << "汪汪" << endl;
	}
	void watch_home()
	{
		cout << "watch home" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void cry()
	{
		cout << "喵喵" << endl;
	}
	void catch_mouse()
	{
		cout << "catch mouse" << endl;
	}
};

void main_test(Animal* base)
{
	base->cry();//1.有继承 2.有虚函数重写 3.父类指针指向子类对象----多态

	//dynamic_cast 运行时类型识别
	Dog* dogx = dynamic_cast<Dog*>(base);//父类对象转子类对象
	if (dogx!=NULL)
	{
		dogx->watch_home();
	}
	Cat* catx = dynamic_cast<Cat*>(base);
	if (catx != NULL)
	{
		catx->catch_mouse();
	}

}


int main()
{
	Dog dog1;
	Cat cat1;
	main_test(&dog1);
	main_test(&cat1);


	cout << "end.." << endl;
	system("pause");
	return 0;
}