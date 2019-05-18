/****************************************!
*@brief  const_cast
*@author ZhangYunjia
*@date   2019/5/18/15:32

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void print_buf(const char* obj)//要确保obj所指向的内存空间确实可以修改
{
	//obj[0] = 'Z';
	char* p = NULL;
	p = const_cast<char*>(obj);
	p[0] = 'Z';
	cout << obj << endl;

}


int main()
{
	{
		char buf[] = "zyj";
		print_buf(buf);

	}


	{
		const char* name = "zyj";
		char *buf2 = new char[strlen(name) + 1];
		strcpy(buf2, name);
		cout << buf2 << endl;
		print_buf(buf2);
		delete[] buf2;
	}



	//{   //err:
	//	const char* name = "zyj";
	//	print_buf(name);
	//}



	cout<<"end.."<<endl;
	system("pause");
	return 0;
}