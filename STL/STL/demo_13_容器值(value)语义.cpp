/****************************************!
*@brief  ����ֵ(value)����
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
	//copy���캯��,ʵ�ֹ���Teacher t2=t1;
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
	//���صȺŲ�������t3=t2=t1
	Teacher & operator=(const Teacher &obj)
	{
		//1.�Ȱ�t2�ľ��ڴ��ͷŵ�
		if (name!=NULL)
		{
			delete[] name;
			name = NULL;
			age = 0;
		}

		//2.����t1�Ĵ�С�����ڴ�
		name = new char[strlen(obj.name) + 1];

		//3.copy t1������
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
	v1.push_back(t1);//��t1����һ�ݷ���������

}

int main()
{

	test();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
