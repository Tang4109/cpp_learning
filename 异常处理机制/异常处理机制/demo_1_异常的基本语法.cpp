/****************************************!
*@brief  �쳣�Ļ����﷨
*@author ZhangYunjia
*@date   2019/5/18/16:03

****************************************/

#include<iostream>

using namespace std;

void divide(int x, int y)
{
	if (y==0)
	{
		throw x;//�׳� int���͵��쳣

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
		my_divide(100, 0);//�쳣�ǿ纯����
	}
	catch (int e)
	{
		cout << e << "��0��" << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}