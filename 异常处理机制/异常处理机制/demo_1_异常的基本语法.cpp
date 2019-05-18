/****************************************!
*@brief  异常的基本语法
*@author ZhangYunjia
*@date   2019/5/18/16:03

****************************************/

#include<iostream>

using namespace std;

void divide(int x, int y)
{
	if (y==0)
	{
		throw x;//抛出 int类型的异常

	}
	cout << "x/y=" << x / y << endl;
}

void my_divide(int x, int y)
{
	divide(x, y);
}


int main()
{
	try
	{
		//divide(10, 2);
		//divide(100, 0);
		my_divide(100, 0);//异常是跨函数的
	}
	catch (int e)
	{
		cout << e << "被0除" << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}