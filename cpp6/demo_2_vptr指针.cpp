/****************************************!
*@brief  vptr指针占4个字节（32位情况下）
*@author ZhangYunjia
*@date   2019/5/1/10:55

****************************************/

#include<iostream>

using namespace std;

class parent1 {
private:
	int a;
public:
	parent1(int a_ = 0) {
		this->a = a_;

	}
	virtual void print() {
		cout << a << endl;
	}

};

class parent2 {
private:
	int a;
public:
	parent2(int a_ = 0) {
		this->a = a_;

	}
	void print() {
		cout << a << endl;
	}
};




int main()
{
	cout << sizeof(parent1) << endl;
	cout << sizeof(parent2) << endl;


	cout << "end.." << endl;
	system("pause");
	return 0;
}