/****************************************!
*@brief  �쳣�������쳣�����������
*@author ZhangYunjia
*@date   2019/5/18/19:32

****************************************/

#include<iostream>

using namespace std;

class zyj
{
public:
	zyj() {
		cout << "zyj���캯��" << endl;
	}
	zyj(const zyj& obj) {
		cout << "copy���캯��" << endl;
	}

	~zyj()
	{
		cout << "zyj��������" << endl;
	}

};

void my_strcpy(char* to, char* from) {
	if (from==NULL)
	{
		throw zyj();
	}
	if (to==NULL)
	{
		throw zyj();
	}
	if (*from=='z')
	{
		throw zyj();
	}

}


int main()
{
	char buf1[] = "zyj";
	char buf2[4] = { 0 };

	try
	{
		my_strcpy(buf2, buf1);
	}

	/*
	catch (zyj e) //1.��һ��Ԫ�أ���copy�����쳣����
	{
		;
	}
	//2.ָ����Ժ�����/Ԫ��д��һ��
	catch (zyj *e)//�����׳�һ����ַ
	{
		;
	}
	*/
	//3.ע�⣺���ú�Ԫ�ز���ͬʱ����
	catch (zyj &e) //ʹ�����û�ֱ��ʹ��throw���Ǹ����󣬶�������copy���캯��
	{
		;
	}
	//���ۣ������׳���������������ʹ������
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
	}
	
	
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}