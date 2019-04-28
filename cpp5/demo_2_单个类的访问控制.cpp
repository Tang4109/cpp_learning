/****************************************!
*@brief  类的访问控制
*@author ZhangYunjia
*@date   2019/4/28/8:20

****************************************/


#include<iostream>

using namespace std;

class parent
{

public:
	int a;
protected:
	int b;
private:
	int c;

public:
	void print() {
		cout << a << endl << b << endl << c << endl;
	}

	 
};

class child :public parent
{
public:
	void use_var() {
		a = 1;
		b = 2;
		//c = 3;//err

	}
protected:

}; 

int main()
{
	parent p1;
	child c1;
	c1.a = 1;
	//c1.b = 2;//err
	//c1.c = 3;
	c1.use_var();
	c1.print();

	cout << "end.." << endl;
	system("pause");
	return 0;
}