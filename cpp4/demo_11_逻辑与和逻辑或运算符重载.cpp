/****************************************!
*@brief  �߼�����߼�������������޷�ʵ�ֶ�·����
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
		cout << "+�����غ���" << endl;
		ret.i = i + obj.i;
		return ret;

	}
	bool operator&&(const Test&obj) {
		cout << "&&�����غ���" << endl;
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
	cout << "&&�������Ľ��˳���Ǵ�������" << endl;
	if (a1&&(a1+a2))
	{
		//��·����
		cout << "a1�Ǽ�����ִ��(a1+a2)" << endl;
	}
	Test t1 = 0;
	Test t2 = 1;
	if (t1 && (t1 + t2))
	{
		//�޷�ʵ�ֶ�·����
		cout << "t1��(t1+t2)��ִ�У�����ִ��+" << endl;
	}

	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}