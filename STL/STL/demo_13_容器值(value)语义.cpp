/****************************************!
*@brief  容器值(value)语义
*@author ZhangYunjia
*@date   2019/5/27/15:52

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "vector"
using namespace std;


class Teacher
{
public:
	Teacher(const char* name_, int age_)
	{
		age = age_;
		name = new char[strlen(name_)+1];
		strcpy(name, name_);
		//name = name_;
	}
	//copy构造函数,实现功能Teacher t2=t1;
	Teacher(const Teacher& obj)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		age = obj.age;
	}

	~Teacher()
	{
		if (name!=NULL)
		{
			delete[] name;
			name = NULL;
			age = 0;
		}

	}

	void print()
	{
		cout << name << ":" << age << endl;

	}
	//重载等号操作符：t3=t2=t1
	Teacher & operator=(const Teacher &obj)
	{
		//1.先把t2的旧内存释放掉
		if (name!=NULL)
		{
			delete[] name;
			name = NULL;
			age = 0;
		}

		//2.根据t1的大小分配内存
		name = new char[strlen(obj.name) + 1];

		//3.copy t1的数据
		strcpy(name, obj.name);
		age = obj.age;
		return *this;
	}


private:
	char* name;
	int age;
 };

void test()
{
	Teacher t1("t1", 31);
	t1.print();
	vector<Teacher> v1;
	v1.push_back(t1);//把t1拷贝一份放在容器中

}

int main()
{

	test();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
