/****************************************!
*@brief  输入输出流
*@author ZhangYunjia
*@date   2019/5/23/13:19

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "fstream"
using namespace std;


int main111()
{

	const char* fname = "f:/23.txt";
	ofstream fout(fname);//建立一个输出流对象和文件关联
	//写文件
	fout << "hello...1" << endl;
	fout << "hello...2" << endl;
	fout << "hello...3" << endl;
	fout.close();
	//读文件
	ifstream fin(fname);//建立一个输入流对象和文件关联
	
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}

class Teacher
{
public:
	Teacher() {
		age = 33;
		strcpy(name, "");
	}

	Teacher(int age,const char*name) {
		this->age = age;
		strcpy(this->name, name);
	}
	void prints() {
		cout << age << " " << name << endl;
	}
protected:
private:
	int age;
	char name[32];
};

int main()   /* 2019/5/23/13:43 */
{

	const char* fname = "f:/1.txt";
	ofstream fout(fname,ios::binary);//建立一个输出流对象和文件关联
	//写文件
	
	Teacher t1(31, "t31");
	Teacher t2(32, "t32");

	fout.write((char*)&t1, sizeof(t1));
	fout.write((char*)&t2, sizeof(t2));

	fout.close();

	ifstream fin(fname);
	Teacher tmp;
	fin.read((char*)&tmp,sizeof(Teacher));
	tmp.prints();

	fin.read((char*)&tmp, sizeof(Teacher));
	tmp.prints();

	fin.close();

	system("pause");
	return 0;
}