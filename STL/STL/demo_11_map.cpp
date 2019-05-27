/****************************************!
*@brief  map
*@author ZhangYunjia
*@date   2019/5/27/8:46

****************************************/

#include<iostream>
#include "map"
#include "string"

using namespace std;

void print(map<int, string>& map1)
{
	for (map<int, string>::iterator it=map1.begin();it!=map1.end();it++)
	{
		cout << it->first << ":" << it->second << endl;
	}


}
//map 容器基础操作
void map_()
{ 
	map<int, string> map1;
	//插入方法1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));
	//插入方法2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));
	//插入方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));
	//插入方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	//遍历
	print(map1);
	//删除
	cout << "头部元素：" << endl;
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << ":" << it->second << endl;
		map1.erase(it);
	}
	cout << "删除之后：" << endl;
	print(map1);
}
//插入的4种方法的异同
//前3种方法返回值是pair<iterator, bool>，如果key已经存在则报错
//第4种方法如果key已经存在则覆盖
void map_compare()
{
	map<int, string> map1;
	//插入方法1
	map1.insert(pair<int, string>(1, "teacher01"));
	pair<map<int, string>::iterator, bool>mypair1 = map1.insert(pair<int, string>(1, "teacher02"));
	if (mypair1.second==true)
	{
		cout << "key5插入成功" << endl;
	}
	else
	{
		cout << "key5插入失败：" << endl;
		cout << mypair1.first->first << ":" << mypair1.first->second << endl;
	}

	
	//插入方法2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));
	//插入方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));
	//插入方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	map1[8] = "teacher88";//覆盖
	//遍历
	cout << "遍历：" << endl;
	print(map1);
	
	//查找
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key 100 的值 不存在" << endl;
	}
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	//equal_range //异常处理
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); //返回两个迭代器 形成一个 pair
																							   //第一个迭代器 >= 5的 位置 
																							   //第一个迭代器 = 5的 位置 

	if (mypair.first == map1.end())
	{
		cout << "第一个迭代器 >= 5的 位置 不存在" << endl;
	}
	else
	{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}

	//使用第二个迭代器
	if (mypair.second == map1.end())
	{
		cout << "第二个迭代器 > 5的 位置 不存在" << endl;
	}
	else
	{
		cout << mypair.second->first << "\t" << mypair.second->second << endl;
	}

	//删除
	cout << "头部元素：" << endl;
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << ":" << it->second << endl;
		map1.erase(it);
	}
	cout << "删除之后：" << endl;
	print(map1);

}


int main()
{

	//map_();
	map_compare();

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}