/****************************************!
*@brief  逻辑与和逻辑或运算符重载无法实现短路规则
*@author ZhangYunjia
*@date   2019/4/26/14:53

****************************************/

#include<iostream>

using namespace std;

class Test
{
public:
	Test(int i) {
		this->i = i;
	}
	Test operator+(const Test& obj) {
		Test ret(0);
		cout << "+号重载函数" << endl;
		ret.i = i + obj.i;
		return ret;

	}
	bool operator&&(const Test&obj) {
		cout << "&&号重载函数" << endl;
		return i && obj.i;
	}

protected:
private:
	int i;
};


int main()
{
	int a1 = 0;
	int a2 = 1;
	cout << "&&操作符的结合顺序是从左至右" << endl;
	if (a1&&(a1+a2))
	{
		//短路规则
		cout << "a1是假则不再执行(a1+a2)" << endl;
	}
	Test t1 = 0;
	Test t2 = 1;
	if (t1 && (t1 + t2))
	{
		//无法实现短路规则
		cout << "t1与(t1+t2)都执行，且先执行+" << endl;
	}

	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}