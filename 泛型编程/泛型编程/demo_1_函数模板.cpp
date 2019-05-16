/****************************************!
*@brief  函数模板(tmplate)
*@author ZhangYunjia
*@date   2019/5/16/10:50

****************************************/

#include<iostream>

using namespace std;
//写n个函数，交换char类型、int类型、double类型变量的值。
//函数的参数类型不同
class swaps {
public:
	 void my_swap(int &a, int &b) {
		int c = 0;
		c = a;
		a = b;
		b = c;


	}

	void my_swap(char &a, char &b) {
		int c = 0;
		c = a;
		a = b;
		b = c;

	}


};


//有必要让函数的参数类型参数化--函数模板（泛型编程）
//tmplate告诉c++编译器，要开始泛型编程了，看到T不要随便报错
template <typename T>

void my_swap(T &a,T &b) {
	T c;
	c = a;
	a = b;
	b = c;

}


int main()
{
	//原始方式
	{
		swaps swaps_int;
		int x = 10;
		int y = 20;
		swaps_int.my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
	}
	{
		swaps swaps_char;
		char x = 'x';
		char y = 'y';
		swaps_char.my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
	}
	//泛型编程-函数模板的调用：1.显式类型调用 2.自动类型推导

	cout << "******************************" << endl;
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

	{
		char x = 'x';
		char y = 'y';
		my_swap<char>(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;
		//2.自动类型推导
		my_swap(x, y);
		cout << "x: " << x << endl << "y: " << y << endl;

	}


	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}