/****************************************!
*@brief  数组模板类框架
*@author ZhangYunjia
*@date   2019/5/17/10:10

****************************************/

#include<iostream>
#include "my_vector.cpp"
using namespace std;


int main()
{
	my_vector<int> my_v1(10);
	int len = my_v1.get_len();
	for (int i = 0;i< len;i++)
	{
		my_v1[i] = i;
		cout << my_v1[i] << " ";
	}
	cout << endl;
	my_vector<int>my_v2 = my_v1;
	
	for (int i = 0; i < len; i++)
	{
		cout << my_v2[i] << " ";
	}

	my_vector<int>my_v3;
	my_v3 = my_v1;

	//重载左移运算符
	cout << my_v3 << endl;

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}