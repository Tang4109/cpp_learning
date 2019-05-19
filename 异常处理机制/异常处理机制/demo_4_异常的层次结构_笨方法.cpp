/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/19/14:14

****************************************/

#include<iostream>

using namespace std;

class eNegative {};
class eZero {};
class eTooBig {};
class eTooSmall {};

class my_array
{
public:
	//构造函数没有返回值，所以适用于使用异常进行处理
	my_array(int len_) {
		if (len_<0)
		{
			throw eNegative();
		}
		else if (len_==0)
		{
			throw eZero();
		}
		else if (len_ > 1000)
		{
			throw eTooBig();
		}
		else if (0 <= len_ < 10)
		{
			throw eTooSmall();
		}
		

		m_len = len_;
		m_space = new int[m_len];
	}
	~my_array()
	{
		if (m_space!=NULL)
		{
			delete[] m_space;
			m_space = NULL;
			m_len = 0;
		}
	}
public:
	//中括号重载
	int& operator[](int index) { 
		return m_space[index];
	}
public:
	int get_len() {
		return m_len;
	}
	int set_len(int len_) {
		m_len = len_;
	}
protected:
private:
	int* m_space;
	int m_len;
};

int main()
{
	try
	{
		my_array a(-5);
		//int size = a.get_len();
		//for (int i = 0; i < size; i++)
		//{
		//	a[i] = i + 1;
		//	cout << a[i] << endl;
		//}
	}
	catch (eNegative& e)
	{
		;
	}
	catch (...) {
		cout << "未知异常" << endl;
	}

	
	
	


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}