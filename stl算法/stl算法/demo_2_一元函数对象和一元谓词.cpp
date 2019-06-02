/****************************************!
*@brief  һԪ���������һԪν��
*@author ZhangYunjia
*@date   2019/6/2/16:44

****************************************/

#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;


template<typename T>
class isDiv
{
public:
	isDiv(const T& divisor)
	{
		this->divisor = divisor;
	}

	bool operator()(T& t)
	{
		return (t%divisor == 0);
	}

private:
	T divisor;


};


int main()
{
	vector<int> v;
	for (int i=5;i<30;i++)
	{
		v.push_back(i+1);
	}
	int a = 4;
	isDiv<int> myDiv(a);

	vector<int>::iterator it;
	it = find_if(v.begin(), v.end(), myDiv);//����һ��������
	if (it==v.end())
	{
		cout << "������û�б�4������Ԫ��" << endl;
	}
	else
	{
		cout << "��һ����4������Ԫ���ǣ�"<< *it << endl;

	}

	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}