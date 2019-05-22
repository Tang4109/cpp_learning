/****************************************!
*@brief  标准输入cin
*@author ZhangYunjia
*@date   2019/5/22/19:38

****************************************/

#include<iostream>

using namespace std;


int main()
{
	char my_buf[1024];
	int my_int;
	long my_long;

	cin >> my_int;
	cin >> my_long;

	cin >> my_buf;//遇见空格停止接收数据
	cout << "my_int:" << my_int << endl;
	cout << "my_long:" << my_long << endl;
	cout << "my_buf:" << my_buf << endl;


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}