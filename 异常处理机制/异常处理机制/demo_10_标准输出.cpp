/****************************************!
*@brief  cout.put/cout.write/cout.fill/cout.setf
*@author ZhangYunjia
*@date   2019/5/23/12:12

****************************************/

#include<iostream>
#include "iomanip"
using namespace std;


int main101()
{

	cout.put('h').put('e').put('\n');
	const char* p = "hello zyj";
	cout.write(p, strlen(p)) << endl;
	cout.write(p, strlen(p)-4) << endl;
	cout.write(p, strlen(p)+4) << endl;


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}

int main102()   /* 2019/5/23/13:05 */
{
	//���Ա����
	cout << "<start>";
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase); //#include <iomanip>
	cout.setf(ios::internal); //����
	cout << hex << 123 << "<End>\n";

	system("pause");
	return 0;
}

int main()   /* 2019/5/23/13:09 */
{
	//ʹ�ÿ��Ʒ�
	cout << "<Start>"
		<< setw(30)
		<< setfill('*')
		<< setiosflags(ios::showbase) //����
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<End>\n"
		<< endl;

	system("pause");
	return 0;
}