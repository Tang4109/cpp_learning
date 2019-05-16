/****************************************!
*@brief  函数模板做函数参数
*@author ZhangYunjia
*@date   2019/5/16/12:35

****************************************/

#include<iostream>

using namespace std;
//对字符数组，int数组进行排序

template<typename T>
int my_sort(T* array, int size) {
	T tmp=0;//中间变量
	if (array==NULL)
	{
		return -1;
	}
	for (int i=0;i<size;i++)
	{
		for (int j=i+1;j<size;j++)
		{
			if (array[i]>array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	return 0;
}
template<typename T>
int print_sort(T* array, int size) {
	if (array == NULL)
	{
		return -2;
	}
	int i = 0;
	for (i=0;i<size;i++)
	{
		cout << array[i];
	}
	return 0;
}

int main()
{
	int flag = 0;
	//int array[] = { 11,45,22,33,7,5,69,45,18 };
	//char array[] = { 'daa','zyj','zrf','xhh','ljh','xp','mzq','ser','hth' };
	char array[] = "hfhj";
	//cout << sizeof(array) << endl;
	//cout << sizeof(*array) << endl;
	//cout << sizeof(array[0]) << endl;
	int size = sizeof(array) / sizeof(*array);
	cout << "原数组:" << endl;
	flag = print_sort(array, size-1);//-1是为了不排空格（\0）
	if (flag != 0)
	{
		cout << "func print_sort() err: " << flag << endl;
	}

	my_sort<char>(array, size-1);
	cout << "\n排序结果:" << endl;
	flag = print_sort<char>(array,size);
	if (flag!=0)
	{
		cout << "func print_sort() err: " << flag << endl;
	}

	cout<<"\nend.."<<endl;
	system("pause");
	return flag;
}