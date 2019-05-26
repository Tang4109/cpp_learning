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


//1.基本操作
void list_()
{
	list<int> L;
	cout << "L的大小：" << L.size() << endl;
	for (int i=0;i<10;i++)
	{
		L.push_back(i);//尾部插入元素


	}
	cout << "L的大小：" << L.size() << endl;
	//遍历
	print(L);
	//list不支持随机访问容器：it=it+5 err
	list<int>::iterator it = L.begin();
	L.insert(it, 100);
	print(L);
	//删除
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