/****************************************!
*@brief  À¨ºÅÔËËã·ûÖØÔØ
*@author ZhangYunjia
*@date   2019/4/26/14:32

****************************************/

#include<iostream>

using namespace std;

class F {
public:
	int operator()(int i, int j) {
		return i * i + j * j;
	}
	
};


int main()
{
	F f;
	cout << f(2, 4) << endl;
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}