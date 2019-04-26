/****************************************!
*@brief  重载等号操作符
*@author ZhangYunjia
*@date   2019/4/26/10:15

****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Name
{
public:
	Name(const char *_p)
	{
		len = strlen(_p);
		p = (char *)malloc(len + 1);
		strcpy(p, _p);//浅拷贝
	}
	//解决浅拷贝的问题：
	//手工地编写copy构造函数，使用深copy
	//不使用c++编译器提供的默认copy构造函数
	Name(const Name& obj)
	{
		len = obj.len;
		p = (char *)malloc(len + 1);//分配新的内存空间
		strcpy(p, obj.p);

	}
	//重载等号操作符
	Name& operator=(Name &obj) {
		if (this->p!=NULL)
		{
			free(p);
			len = 0;
		}

		this->len = obj.len;
		this->p = new char[len+1];
		strcpy(p, obj.p);

		return *this;
	}

	~Name()
	{

		if (p != NULL)
		{
			free(p);
			p = NULL;
			len = 0;
		}

	}
public:
	char *p;
	int len;

};

void objects()
{

	Name obj1("obj1");
	Name obj2 = obj1;//如果不定义copy构造函数，则使用c++编译器提供的默认copy构造函数
	cout << obj2.p << endl;
	/*
	*	浅拷贝：
	obj2与obj1指向同一块内存空间
	使用完之后obj2先释放，obj1成为野指针，当obj1再释放时发生中断
	*/

	Name obj3("obj3");
	cout << obj3.p << endl;
	obj3 = obj1;//c++编译器提供的等号操作也是一个浅拷贝，需要显式地重载等号操作符
	cout << obj3.p << endl;


	cout << "**************************" << endl;
	obj1 = obj2 = obj3;
	cout << obj3.p << endl;
	cout << obj2.p << endl;
	cout << obj1.p << endl;

}


int main()
{
	objects();


	cout << "END..." << endl;
	system("pause");
	return 0;
}
