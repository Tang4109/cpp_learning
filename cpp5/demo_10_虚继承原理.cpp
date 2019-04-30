/****************************************!
*@brief  –ÈºÃ≥–‘≠¿Ì
*@author ZhangYunjia
*@date   2019/4/29/15:27

****************************************/

#include<iostream>

using namespace std;

class B{
public:
	int a;

};

class B1 :virtual public B {
public:
	int b;

};

class B2 :public B {
public:
	int b;

};


int main()
{
	cout << sizeof(B) << endl;
	cout << sizeof(B1) << endl;
	cout << sizeof(B2) << endl;
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}