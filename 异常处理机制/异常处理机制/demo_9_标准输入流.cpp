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
	//cin.getһ��ֻ�ܶ�ȡһ���ַ�
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

	//cin.get(һ������) //��һ���ַ�
	char a, b, c;
	cin.get(a);
	cin.get(b);
	cin.get(c);
	//�����������ݣ����򲻻�����
	cout << a << b << c << endl;
	//��ʽ���
	cin.get(a).get(b).get(c);
	cout << a << b << c << endl;

	system("pause");
	return 0;
}
int main93()   /* 2019/5/23/8:30 */
{

	//cin.getline() ���Խ��ܿո�
	char buf1[256];
	char buf2[256];
	cout << "������һ�����ж���ո���ַ�����" << endl;

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
	cout << "������һ�����ж���ո���ַ�����" << endl;

	cin >> buf1;
	cin.ignore(2);//���������ո�
	int my_int = cin.peek();//���ػ������ĵ�һ��Ԫ��
	cout << "my_int: " << my_int << endl;
	cin.getline(buf2, 256);

	cout << "buf1:" << buf1 << "buf2:" << buf2 << endl;

	system("pause");
	return 0;
}

int main()   /* 2019/5/23/9:02 */
{
	char c = cin.get();
	if ((c >= '0') && (c <= '9')) //������������ַ��� �ֿ�����
	{
		int n; //���������� �м��пո� ʹ��cin >>n
		cin.putback(c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str); // //�ַ��� �м�����пո� ʹ�� cin.getline();
		cout << "You entered a word: " << str << '\n';
	}


	system("pause");
	return 0;
}


