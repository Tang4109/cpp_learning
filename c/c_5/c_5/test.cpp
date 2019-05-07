/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/6/11:22

****************************************/

#include<iostream>

using namespace std;

int sort(const char **p_,int num1,char(*p2_)[30],int num2,char ***p3_,int * num3) {

	return 0;

}
void sort_free01(char **p, int len) {
	int i = 0;
	if (p == NULL) {
		return;
	}

	for (i=0;i<len;i++)
	{
		free(p[i]);
	}
	free(p);
	//p = NULL;//err:p已经被释放了
}

void sort_free02(char ***p_, int len) {
	int i = 0;
	//if (p_ == NULL) {
	//	return;
	//}
	char **p = *p_;
	for (i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	*p_ = NULL;//p_间接赋值p，函数结束后p_自动释放
}


int main01()
{
	int ret = 0;
	const char *p1[] = { "aaaaa","ccccc","bbbbb" };
	char buf2[10][30] = { "11111","33333","22222" };
	char ***p3 = NULL;
	int len1, len2, len3;
	

	//cout << sizeof(p1) << endl;
	//cout << sizeof(*p1) << endl;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;
	ret = sort(p1, len1, buf2, len2, &p3, &len3);

	if (ret!=0)
	{
		cout << "func sort() err: " << ret << endl;
		system("pause");
		return ret;
	}
	for (int i=0;i<len3;i++)
	{
		cout << p3[i] << endl;
	}

	cout<<"end.."<<endl;
	system("pause");
	return ret;
}