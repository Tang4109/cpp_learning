/****************************************!
*@brief  异常类型与异常变量
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
		throw xhh();
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
	catch (zyj e) //copy构造异常变量
	{
		;
	}
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