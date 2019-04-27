/****************************************!
*@brief  ¼Ì³ÐµÄ»ù´¡Óï·¨
*@author ZhangYunjia
*@date   2019/4/27/15:13

****************************************/

#include<iostream>

using namespace std;

class parent
{
public:
	void print() {
		cout << a << endl << b << endl;
	}
protected:
public:
	int a;
	int b;

};

class child:public parent
{
public:
protected:
private:
	int c;
}; 




int main()
{

	parent p1;
	child c1;
	c1.a;
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}