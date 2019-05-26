/****************************************!
*@brief  priority_queue
*@author ZhangYunjia
*@date   2019/5/26/16:11

****************************************/

#include<iostream>
#include "queue"
#include <functional>
using namespace std;

void print(priority_queue<int, vector<int>, greater<int>>& p)
{
	while (p.size()>0)
	{
		cout << p.top() << " ";
		p.pop();

	}


}

void priority_queue_()
{
	//priority_queue<int> p;//默认最大值优先队列
	//priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > p;

	p.push(1);
	p.push(5);
	p.push(46);
	p.push(37);
	p.push(19);
	print(p);
}

int main()
{

	priority_queue_();
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}