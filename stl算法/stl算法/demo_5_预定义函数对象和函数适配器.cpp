/****************************************!
*@brief  Ԥ���庯������ͺ���������
*@author ZhangYunjia
*@date   2019/6/3/16:37

****************************************/

#include<iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

template<typename T>
void FuncShowElemt(T &t)
{
	cout << t << " ";
}

//����������
int main()
{

	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y);
	cout << "z:" << z << endl;
	
	plus<string> strAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = strAdd(s1, s2);
	cout << s3 << endl;

	vector<string> v1;
	v1.push_back("aaa");
	v1.push_back("bbb");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("ccc");
	v1.push_back("zzz");
	//����
	sort(v1.begin(), v1.end(),greater<string>());
	for_each(v1.begin(), v1.end(), FuncShowElemt<string>);

	//����
	string sc = "ccc";
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));//bind2nd-��������������Ԥ���庯������͵ڶ����������а�
	cout << endl;
	cout << "sc���ֵĴ���:" << num << endl;

	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}