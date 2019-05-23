/****************************************!
*@brief  cin.get/cin.getline/cin.ignore/ cin.peek/cin.putback
*@author ZhangYunjia
*@date   2019/5/22/20:24

****************************************/

#include<iostream>
#include<string>
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
int main93()   /* 2019/5/23/8:30 */
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

int main94()   /* 2019/5/23/8:41 */
{

	char buf1[256];
	char buf2[256];
	cout << "请输入一个含有多个空格的字符串：" << endl;

	cin >> buf1;
	cin.ignore(2);//忽略两个空格
	int my_int = cin.peek();//返回缓冲区的第一个元素
	cout << "my_int: " << my_int << endl;
	cin.getline(buf2, 256);

	cout << "buf1:" << buf1 << "buf2:" << buf2 << endl;

	system("pause");
	return 0;
}

int main()   /* 2019/5/23/9:02 */
{
	char c = cin.get();
	if ((c >= '0') && (c <= '9')) //输入的整数和字符串 分开处理
	{
		int n; //整数不可能 中间有空格 使用cin >>n
		cin.putback(c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str); // //字符串 中间可能有空格 使用 cin.getline();
		cout << "You entered a word: " << str << '\n';
	}


	system("pause");
	return 0;
}


