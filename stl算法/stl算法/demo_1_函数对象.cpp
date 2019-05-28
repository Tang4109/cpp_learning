/****************************************!
*@brief  函数对象
*@author ZhangYunjia
*@date   2019/5/28/8:41

****************************************/

#include<iostream>
#include "string"
#include "vector"
#include "list"
#include "set"
#include <algorithm>
#include <functional>

using namespace std;


//函数对象：类重载()
template<typename T>
class show_element
{
public:
	show_element()
	{
		n = 0;
	}

	void operator()(T& t)
	{
		n++;
		cout << t << endl;
	}
	void print()
	{
		cout << "n:" << n << endl;
	}

protected:
private:
	int n;
};

//函数模板  ==函数
template <typename T>
void FuncShowElemt(T &t)
{
	cout << t << endl;
}
//普通函数
void FuncShowElemt2(int &t)
{
	cout << t << endl;
}
//函数对象和普通函数的异同

void test()
{
	int a = 10;
	show_element<int> s_e;
	s_e(a);//函数对象()的执行很像一个函数->仿函数
	FuncShowElemt<int>(a);
	FuncShowElemt2(a);

}
//函数对象是属于类对象,能突破函数的概念,能保持调用状态信息
//函数对象的好处
// for_each算法中, 函数对象做函数参数
// for_each算法中, 函数对象当返回值
void test_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), show_element<int>()); //匿名函数对象 匿名仿函数
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElemt2); //通过回调函数  谁使用for_each 谁去填写回调函数的入口地址


	show_element<int> show1;
	//函数对象 做函数参数 
	//1 for_each算法的 函数对象的传递 是元素值传递 ,不是引用传递
	for_each(v1.begin(), v1.end(), show1);
	show1.print();
	cout << "通过for_each算法的返回值看调用的次数" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);
	show1.print();
	//结论 要点: 分清楚 stl算法返回的值是迭代器 还是 谓词（函数对象） 

}





int main()
{

	test();
	test_foreach();
	cout<<"end.."<<endl;
	system("pause");
	return 0;
}