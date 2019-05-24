/****************************************!
*@brief  ͨ���������ķ�ʽ��������
*@author ZhangYunjia
*@date   2019/5/24/15:15

****************************************/

#include<iostream>
#include "vector"
using namespace std;

//����ͷ��β��Ԫ�ص���Ӻ�ɾ��/�޸�
void vector_base() {
	
	vector<int> v1;
	cout << "size: " << v1.size() << endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "size: " << v1.size() << endl;

	
	while (v1.size()>0)
	{
		cout << "v1.front(): " << v1.front() << endl;
		cout << "v1.back(): " << v1.back() << endl;
		break;
	}
	//����
	v1.pop_back();
	cout << "v1.back(): " << v1.back() << endl;

	//�޸�ͷ��β��Ԫ�ص�ֵ
	v1.front() = 11;//�����������ã���������ֵ����ֵ
	v1.back() = 55;
	while (v1.size() > 0)
	{
		cout << "v1.front(): " << v1.front() << endl;
		cout << "v1.back(): " << v1.back() << endl;
		break;
	}
}
void print(vector<int>& v) 
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}

//vector��ʼ��
void vector_init() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;
	vector<int> v3(v1.begin(),v1.begin()+2);
	vector<int> v4(3, 9);//���3��Ԫ�أ�ÿ��Ԫ�ض���9

	cout << "v1: ";
	print(v1);
	cout << "\nv2: ";
	print(v2);
	cout << "\nv3: ";
	print(v3);
	cout << "\nv4: ";
	print(v4);
}
//vector����
void vector_search() {
	//1.����ķ�ʽ
	vector<int> v1(10);//�����ڴ�ռ�
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	print(v1);
	cout << endl;
	v1.push_back(100);
	print(v1);
}
//ͨ����������������
void vector_iterator()
{
	vector<int> v1(10);//�����ڴ�ռ�
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	//v1.end()��λ������size�ĺ���
	cout << endl;
	//�������
	for (vector<int>::reverse_iterator rit=v1.rbegin();rit!=v1.rend();rit++)
	{
		cout << *rit << " ";
	}

}
//ɾ��/�������
void vector_delete()
{
	vector<int> v1(10);//�����ڴ�ռ�
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	//����ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);
	print(v1);
	//ָ��λ��ɾ��
	v1.erase(v1.begin());
	cout << endl;
	print(v1);
	//����Ԫ�ص�ֵ
	v1[3] = 4;
	cout << endl;
	print(v1);
	for (vector<int>::iterator it=v1.begin();it!=v1.end();)
	{
		if (*it==4)
		{
			it = v1.erase(it);//eraseɾ����������it�Զ�����
			
		}
		else
		{
			it++;
		}
	}
	cout << endl;
	print(v1);

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	cout << endl;
	print(v1);
}

int main()
{

	//vector_base();
	//vector_init();
	//vector_search();
	//vector_iterator();
	vector_delete();
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}