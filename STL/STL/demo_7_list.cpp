/****************************************!
*@brief  list
*@author ZhangYunjia
*@date   2019/5/26/14:29

****************************************/

#include<iostream>
#include "list"
using namespace std;

void print(list<int>& L)
{
	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


//1.��������
void list_()
{
	list<int> L;
	cout << "L�Ĵ�С��" << L.size() << endl;
	for (int i=0;i<10;i++)
	{
		L.push_back(i);//β������Ԫ��


	}
	cout << "L�Ĵ�С��" << L.size() << endl;
	//����
	print(L);
	//list��֧���������������it=it+5 err
	list<int>::iterator it = L.begin();
	L.insert(it, 100);
	print(L);
	//ɾ��
	L.remove(5);
	print(L);
}


int main()
{

	list_();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}