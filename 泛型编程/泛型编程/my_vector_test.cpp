/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/17/10:10

****************************************/

#include<iostream>
#include "my_vector.cpp"
using namespace std;


int main()
{
	my_vector<int> my_v1(10);
	for (int i = 0;i<my_v1.get_len();i++)
	{
		my_v1[i] = i;
		cout << my_v1[i] << " ";
	}
	cout << endl;
	my_vector<int>my_v2 = my_v1;
	for (int i = 0; i < my_v1.get_len(); i++)
	{
		cout << my_v2[i] << " ";
	}

	//ÖØÔØ×óÒÆÔËËã·û
	cout << my_v2 << endl;

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}