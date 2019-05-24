/****************************************!
*@brief  deque
*@author ZhangYunjia
*@date   2019/5/24/19:47

****************************************/

#include<iostream>
#include "deque"
using namespace std;

void print(deque<int>& d)
{
	cout << "����Ԫ��:";
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
}
void deque_()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(5);

	d.push_front(-1);
	d.push_front(-3);
	d.push_front(-5);
	cout << "size: " << d.size() << endl;
	print(d);

	d.pop_front();
	cout << endl;
	print(d);
	d.pop_back();
	cout << endl;
	print(d);
	cout << endl;
	//��������ĳֵ���±�
	deque<int>::iterator it = find(d.begin(), d.end(), 1);
	if (it!=d.end())
	{
		cout << "3���±�:" << distance(d.begin(), it) << endl;
	}
	else
	{
		cout << "û�и�Ԫ��" << endl;
	}

}


int main()
{

	deque_();
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}