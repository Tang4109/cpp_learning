/****************************************!
*@brief  cin.get/cin.getline
*@author ZhangYunjia
*@date   2019/5/22/20:24

****************************************/

#include<iostream>

using namespace std;


int main91()
{
	//cin.get一次只能读取一个字符
	char ch;
	while ((ch=cin.get())!=EOF)
	{
		cout << ch << endl;
	}
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}
int main92()   /* 2019/5/23/8:23 */
{

	//cin.get(一个参数) //读一个字符
	char a, b, c;
	cin.get(a);
	cin.get(b);
	cin.get(c);
	//缓冲区有数据，程序不会阻塞
	cout << a << b << c << endl;
	//链式编程
	cin.get(a).get(b).get(c);
	cout << a << b << c << endl;

	system("pause");
	return 0;
}
int main()   /* 2019/5/23/8:30 */
{

	//cin.getline() 可以接受空格
	char buf1[256];
	char buf2[256];
	cout << "请输入一个含有多个空格的字符串：" << endl;

	cin >> buf1;
	cin.getline(buf2, 256);

	cout << "buf1:" << buf1 << "buf2:" << buf2 << endl;
	
	system("pause");
	return 0;
}
