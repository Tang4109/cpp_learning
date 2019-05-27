/****************************************!
*@brief  multimap
*@author ZhangYunjia
*@date   2019/5/27/12:55

****************************************/

#include<iostream>
#include "map"
#include "string"
using namespace std;

class Person
{
public:
	string name;
	int age;
	string tel;
	double salary;
};

void print(multimap<string, Person>& map1)
{
	for (multimap<string, Person>::iterator it=map1.begin();it!=map1.end();it++)
	{
		cout << it->first<<" " << it->second.name << ":" << it->second.age << endl;
	}
	cout << "遍历结束" << endl;

}
void multimap_()
{
	Person p1, p2, p3, p4, p5;
	p1.name = "zyj";
	p1.age = 31;

	p2.name = "ljh";
	p2.age = 32;

	p3.name = "zrf";
	p3.age = 33;

	p4.name = "xhh";
	p4.age = 34;

	p5.name = "lyx";
	p5.age = 35;

	multimap<string, Person> map1;
	map1.insert(make_pair("sale", p1));
	map1.insert(make_pair("sale", p2));
	map1.insert(make_pair("development", p3));
	map1.insert(make_pair("development", p4));
	map1.insert(make_pair("development", p5));

	print(map1);
	int num= map1.count("development");
	cout << "development部门人数: " << num << endl;
	multimap<string, Person>:: iterator it2 = map1.find("development");
	int tag = 0;
	while (tag<num)
	{
		cout << it2->first << " " << it2->second.name << ":" << it2->second.age << endl;
		it2++;
		tag++;
	}
	//修改
	cout << "修改" << endl;
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		if (it->second.age==32)
		{
			it->second.name = "30280";
		}
	}
	print(map1);

}


int main()
{
	multimap_();
	
	
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}