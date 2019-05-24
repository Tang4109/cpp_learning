/****************************************!
*@brief  通过迭代器的方式访问数组
*@author ZhangYunjia
*@date   2019/5/24/15:15

****************************************/

#include<iostream>
#include "vector"
using namespace std;

//数组头部尾部元素的添加和删除/修改
void vector_base() {
	
	vector<int> v1;
	cout << "size: " << v1.size() << endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "size: " << v1.size() << endl;

	
	while (v1.size()>0)
	{
		cout << "v1.front(): " << v1.front() << endl;
		cout << "v1.back(): " << v1.back() << endl;
		break;
	}
	//弹出
	v1.pop_back();
	cout << "v1.back(): " << v1.back() << endl;

	//修改头部尾部元素的值
	v1.front() = 11;//函数返回引用，函数返回值当左值
	v1.back() = 55;
	while (v1.size() > 0)
	{
		cout << "v1.front(): " << v1.front() << endl;
		cout << "v1.back(): " << v1.back() << endl;
		break;
	}
}
void print(vector<int>& v) 
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

}

//vector初始化
void vector_init() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;
	vector<int> v3(v1.begin(),v1.begin()+2);
	vector<int> v4(3, 9);//存放3个元素，每个元素都是9

	cout << "v1: ";
	print(v1);
	cout << "\nv2: ";
	print(v2);
	cout << "\nv3: ";
	print(v3);
	cout << "\nv4: ";
	print(v4);
}
//vector遍历
void vector_search() {
	//1.数组的方式
	vector<int> v1(10);//分配内存空间
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	print(v1);
	cout << endl;
	v1.push_back(100);
	print(v1);
}
//通过迭代器遍历数组
void vector_iterator()
{
	vector<int> v1(10);//分配内存空间
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	for (vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	{
		cout << *it << " ";
	}
	//v1.end()的位置是在size的后面
	cout << endl;
	//逆序遍历
	for (vector<int>::reverse_iterator rit=v1.rbegin();rit!=v1.rend();rit++)
	{
		cout << *rit << " ";
	}

}
//删除/插入操作
void vector_delete()
{
	vector<int> v1(10);//分配内存空间
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = i;
	}
	//区间删除
	v1.erase(v1.begin(), v1.begin() + 3);
	print(v1);
	//指定位置删除
	v1.erase(v1.begin());
	cout << endl;
	print(v1);
	//根据元素的值
	v1[3] = 4;
	cout << endl;
	print(v1);
	for (vector<int>::iterator it=v1.begin();it!=v1.end();)
	{
		if (*it==4)
		{
			it = v1.erase(it);//erase删除函数会让it自动下移
			
		}
		else
		{
			it++;
		}
	}
	cout << endl;
	print(v1);

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	cout << endl;
	print(v1);
}

int main()
{

	//vector_base();
	//vector_init();
	//vector_search();
	//vector_iterator();
	vector_delete();
	cout<<"\nend.."<<endl;
	system("pause");
	return 0;
}