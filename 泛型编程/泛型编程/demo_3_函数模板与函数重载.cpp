/****************************************!
*@brief  函数重载
*@author ZhangYunjia
*@date   2019/5/16/13:31

****************************************/


#include<iostream>

using namespace std;
//写n个函数，交换char类型、int类型、double类型变量的值。

//有必要让函数的参数类型参数化--函数模板（泛型编程）
//tmplate告诉c++编译器，要开始泛型编程了，看到T不要随便报错
template <typename T>
void my_swap(T &a, T &b) {
	cout << "模板函数" << endl;
	T c;
	c = a;
	a = b;
	b = c;

}

void my_swap(int a, char c) {

	cout << "普通函数" << endl;
	cout << "a:" << a << endl << "c:" << c << endl;

}


int main()
{

	//泛型编程-函数模板的调用：1.显式类型调用 2.自动类型推导

	{
		//1.显式类型调用
		int x = 10;
		int y = 20;
		my_swap<int>(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
		//2.自动类型推导
		my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;

	}

	cout << "******************************" << endl;
	{
		
		int x = 10;
		char y = 'z';
		my_swap(x, y);
		
		my_swap(y, x);//普通函数的调用：可以进行隐式的类型转换
		my_swap(x, x);//模板函数的调用（本质：类型参数化）将严格按照类型进行匹配，不会进行自动类型转换

	}




	cout << "end.." << endl;
	system("pause");
	return 0;
}