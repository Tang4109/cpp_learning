/****************************************!
*@brief ����ʱ����ʶ��
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
		cout << "����" << endl;
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
		cout << "����" << endl;
	}
	void catch_mouse()
	{
		cout << "catch mouse" << endl;
	}
};

void main_test(Animal* base)
{
	base->cry();//1.�м̳� 2.���麯����д 3.����ָ��ָ���������----��̬

	//dynamic_cast ����ʱ����ʶ��
	Dog* dogx = dynamic_cast<Dog*>(base);//�������ת�������
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