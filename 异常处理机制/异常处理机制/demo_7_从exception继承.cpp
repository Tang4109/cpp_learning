/****************************************!
*@brief  从exception继承
*@author ZhangYunjia
*@date   2019/5/22/19:24

****************************************/

#include<iostream>

using namespace std;

class my_except:exception
{
public:
	my_except(const char* m_p) {
		this->m_p = m_p;
	}
	virtual const char* what() {
		cout << "my_except:类型: " << this->m_p << endl;
		return this->m_p;
	}

protected:
private:
	const char* m_p;
};

void test_my_except() {
	throw my_except("函数异常");
}

int main()
{

	try
	{
		test_my_except();
	}
	catch (my_except& e)
	{
		e.what();
	}
	catch (...) {
		cout << "未知异常" << endl;
	}

	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}