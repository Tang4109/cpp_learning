/****************************************!
*@brief  ���صȺŲ�����
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
		strcpy(p, _p);//ǳ����
	}
	//���ǳ���������⣺
	//�ֹ��ر�дcopy���캯����ʹ����copy
	//��ʹ��c++�������ṩ��Ĭ��copy���캯��
	Name(const Name& obj)
	{
		len = obj.len;
		p = (char *)malloc(len + 1);//�����µ��ڴ�ռ�
		strcpy(p, obj.p);

	}
	//���صȺŲ�����
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
	Name obj2 = obj1;//���������copy���캯������ʹ��c++�������ṩ��Ĭ��copy���캯��
	cout << obj2.p << endl;
	/*
	*	ǳ������
	obj2��obj1ָ��ͬһ���ڴ�ռ�
	ʹ����֮��obj2���ͷţ�obj1��ΪҰָ�룬��obj1���ͷ�ʱ�����ж�
	*/

	Name obj3("obj3");
	cout << obj3.p << endl;
	obj3 = obj1;//c++�������ṩ�ĵȺŲ���Ҳ��һ��ǳ��������Ҫ��ʽ�����صȺŲ�����
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
