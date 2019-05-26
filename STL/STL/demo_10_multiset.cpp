/****************************************!
*@brief  multiset
*@author ZhangYunjia
*@date   2019/5/26/21:15

****************************************/

#include<iostream>
#include "set"
using namespace std;

void multiset_()
{
	multiset<int> s;
	int tmp = 0;
	cout << "请输入multiset集合的值：";
	cin >> tmp;
	while (tmp!=0)
	{
		s.insert(tmp);
		cout << "请输入multiset集合的值：";
		cin >> tmp;
	}
	for (multiset<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	while (!s.empty())
	{
		multiset<int>::iterator it = s.begin();
		cout << *it << " ";
		s.erase(it);

	}

}

int main()
{

	multiset_();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}