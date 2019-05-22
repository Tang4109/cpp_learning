/****************************************!
*@brief  标准输入流
*@author ZhangYunjia
*@date   2019/5/22/20:24

****************************************/

#include<iostream>

using namespace std;


int main()
{

	char ch;
	while ((ch=cin.get())!=EOF)
	{
		cout << ch << endl;
	}
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}