/****************************************!
*@brief  异常类型与异常变量（类对象）
*@author ZhangYunjia
*@date   2019/5/18/19:32

****************************************/

#include<iostream>

using namespace std;

class zyj
{
public:
	zyj() {
		cout << "zyj构造函数" << endl;
	}
	zyj(const zyj& obj) {
		cout << "copy构造函数" << endl;
	}

	~zyj()
	{
		cout << "zyj析构函数" << endl;
	}

};

void my_strcpy(char* to, char* from) {
	if (from==NULL)
	{
		throw zyj();
	}
	if (to==NULL)
	{
		throw zyj();
	}
	if (*from=='z')
	{
		throw zyj();
	}

}


int main()
{
	char buf1[] = "zyj";
	char buf2[4] = { 0 };

	try
	{
		my_strcpy(buf2, buf1);
	}

	/*
	catch (zyj e) //1.是一个元素，则copy构造异常变量
	{
		;
	}
	//2.指针可以和引用/元素写在一起
	catch (zyj *e)//必须抛出一个地址
	{
		;
	}
	*/
	//3.注意：引用和元素不能同时出现
	catch (zyj &e) //使用引用会直接使用throw的那个对象，而不调用copy构造函数
	{
		;
	}
	//结论：对于抛出类对象的情况，最好使用引用
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}