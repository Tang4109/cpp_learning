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
//map ������������
void map_()
{
	map<int, string> map1;
	//���뷽��1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));
	//���뷽��2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));
	//���뷽��3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));
	//���뷽��4
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	//����
	print(map1);
	//ɾ��
	cout << "ͷ��Ԫ�أ�" << endl;
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << ":" << it->second << endl;
		map1.erase(it);
	}
	cout << "ɾ��֮��" << endl;
	print(map1);
}
//�����4�ַ�������ͬ
//ǰ3�ַ�������ֵ��pair<iterator, bool>�����key�Ѿ������򱨴�
//��4�ַ������key�Ѿ������򸲸�
void map_compare()
{
	map<int, string> map1;
	//���뷽��1
	map1.insert(pair<int, string>(1, "teacher01"));
	pair<map<int, string>::iterator, bool>mypair1 = map1.insert(pair<int, string>(1, "teacher02"));
	if (mypair1.second==true)
	{
		cout << "key5����ɹ�" << endl;
	}
	else
	{
		cout << "key5����ʧ�ܣ�" << endl;
		cout << mypair1.first->first << ":" << mypair1.first->second << endl;
	}

	
	//���뷽��2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));
	//���뷽��3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));
	//���뷽��4
	map1[7] = "teacher07";
	map1[8] = "teacher08";
	map1[8] = "teacher88";//����
	//����
	cout << "������" << endl;
	print(map1);
	//ɾ��
	cout << "ͷ��Ԫ�أ�" << endl;
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << ":" << it->second << endl;
		map1.erase(it);
	}
	cout << "ɾ��֮��" << endl;
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