/****************************************!
*@brief  ¶à¼Ì³Ð
*@author ZhangYunjia
*@date   2019/4/29/9:10

****************************************/

#include<iostream>

using namespace std;

class base1 {
private:
	int b1;
public:
	base1(int b1) {
		this->b1 = b1;
		cout << b1 << endl;
	}

};

class base2 {

private:
	int b2;
public:
	base2(int b2) {
		this->b2 = b2;
		cout << b2 << endl;
	}

};

class B :public base1, public base2 {
public:
	B(int b1, int b2, int b3) :base1(b1), base2(b2) {
		this->b3 = b3;
		cout << b3 << endl;


	}

private:
	int b3;


};


int main()
{

	B b1(1,2,3);
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}