/****************************************!
*@brief  栈解旋
*@author ZhangYunjia
*@date   2019/5/18/18:05

****************************************/

#include<iostream>

using namespace std;

class Test
{
public:
	Test(int a_, int b_) {
		a = a_;
		b = b_;
		cout << "构造函数" << endl;
	}

	~Test()
	{
		cout << "析构函数" << endl;
	}

private:
	int a;
	int b;
};



void divide(int x, int y)
{
	if (y == 0)
	{
		throw 'z';//抛出 int类型的异常

	}
	cout << "x/y=" << x / y << endl;
}

void my_divide()
{
	Test t1(1, 2);
	Test t2(3, 4);
	cout << "my_divide err" << endl;
	throw 1;
}


int main()
{
	try
	{
		//divide(10, 2);
		//divide(100, 0);
		my_divide();//异常是跨函数的
	}
	catch (int e)
	{
		cout << e << " err" << endl;

	}
	catch (...)//严格按照类型进行匹配
	{
		cout << "未知异常" << endl;
	}



	cout << "end.." << endl;
	system("pause");
	return 0;
}