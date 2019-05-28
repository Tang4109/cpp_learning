/****************************************!
*@brief  ��������
*@author ZhangYunjia
*@date   2019/5/28/8:41

****************************************/

#include<iostream>
#include "string"
#include "vector"
#include "list"
#include "set"
#include <algorithm>
#include <functional>

using namespace std;


//��������������()
template<typename T>
class show_element
{
public:
	show_element()
	{
		n = 0;
	}

	void operator()(T& t)
	{
		n++;
		cout << t << endl;
	}
	void print()
	{
		cout << "n:" << n << endl;
	}

protected:
private:
	int n;
};

//����ģ��  ==����
template <typename T>
void FuncShowElemt(T &t)
{
	cout << t << endl;
}
//��ͨ����
void FuncShowElemt2(int &t)
{
	cout << t << endl;
}
//�����������ͨ��������ͬ

void test()
{
	int a = 10;
	show_element<int> s_e;
	s_e(a);//��������()��ִ�к���һ������->�º���
	FuncShowElemt<int>(a);
	FuncShowElemt2(a);

}
//�������������������,��ͻ�ƺ����ĸ���,�ܱ��ֵ���״̬��Ϣ
//��������ĺô�
// for_each�㷨��, ������������������
// for_each�㷨��, �������󵱷���ֵ
void test_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), show_element<int>()); //������������ �����º���
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElemt2); //ͨ���ص�����  ˭ʹ��for_each ˭ȥ��д�ص���������ڵ�ַ


	show_element<int> show1;
	//�������� ���������� 
	//1 for_each�㷨�� ��������Ĵ��� ��Ԫ��ֵ���� ,�������ô���
	for_each(v1.begin(), v1.end(), show1);
	show1.print();
	cout << "ͨ��for_each�㷨�ķ���ֵ�����õĴ���" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);
	show1.print();
	//���� Ҫ��: ����� stl�㷨���ص�ֵ�ǵ����� ���� ν�ʣ��������� 

}





int main()
{

	test();
	test_foreach();
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}