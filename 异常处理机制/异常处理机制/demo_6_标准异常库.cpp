/****************************************!
*@brief  out_of_range
*@author ZhangYunjia
*@date   2019/5/22/8:47

****************************************/

#include<iostream>
#include <stdexcept>
#include "string"
using namespace std;

class Teacher
{
public:
	Teacher(int age) {
		if (age>100)
		{
			string s = "ÄêÁäÌ«´ó";
			throw out_of_range(s);
		}
		this->age = age;
	}
protected:
private:
	int age;
};


int main()
{
	try
	{
		Teacher t1(102);
	}
	catch (out_of_range e)
	{
		cout << e.what() << endl;
	}

	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}