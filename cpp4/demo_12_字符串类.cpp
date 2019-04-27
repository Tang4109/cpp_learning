/****************************************!
*@brief �ַ�����(�Ⱥ�/�����±�/����/˫�Ⱥ�/���Ⱥ�/С��/����/���� ���������)
*@author ZhangYunjia
*@date   2019/4/26/15:21

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "demo_12_�ַ�����.h"

using namespace std;

my_string::my_string(int length) {
	len = length;
	if (len ==0)
	{
		m_p = new char[len + 1];
		//strcpy(m_p, "");//��ʽ1
		memset(m_p, 0, len);//��ʽ2

	}
	
	m_p = new char[len + 1];
	strcpy(m_p, "");
	
}
my_string::my_string(const char* p) {
	if (p==NULL)
	{
		len = 0;
		m_p = new char[len + 1];
		strcpy(m_p, "");
	}
	else
	{
		len = strlen(p);
		m_p = new char[len + 1];
		strcpy(m_p, p);
	}


}
my_string::my_string(const my_string& s) {
	len = s.len;
	m_p = new char[len + 1];
	strcpy(m_p, s.m_p);


}
my_string::~my_string() {
	if (m_p==NULL)
	{
		delete[] m_p;
		m_p = NULL;
		len = 0;
	}


}

my_string & my_string::operator=(const char*p) {
	if (m_p!=NULL)
	{
		delete[] m_p;
		len = 0;
	}
	if (p==NULL)
	{
		len = 0;
		m_p = new char[len + 1];
		strcpy(m_p, "");

	}
	else {
		len = strlen(p);
		m_p = new char[len + 1];
		strcpy(m_p, p);
	}
	return *this;
}
my_string& my_string::operator=(const my_string& s) {
	if (m_p != NULL)
	{
		delete[] m_p;
		len = 0;
	}

	len = s.len;
	m_p = new char[len + 1];
	strcpy(m_p, s.m_p);
	

	return *this;
}

void my_string::print() {
	cout << m_p << endl;
}

char& my_string::operator[](int index) {

	return m_p[index];
}

ostream& operator<<(ostream &out, my_string& s) {
	out << s.m_p;
	return out;
}
istream& operator>>(istream& in, my_string& s) {
	in >> s.m_p;
	return in;
}

bool my_string::operator==(const char*p) {
	if (p==NULL)
	{
		if (len==0)
			return true;
	} 

	if (len==strlen(p))
		return !strcmp(m_p, p);//��ȷ���0

	return false;
}
bool my_string::operator!=(const char*p) {
	return !(*this == p);//�Ⱥ��Ѿ����ع�
}

bool my_string::operator==(const my_string& s){
	if (len!=s.len)
		return false;

	return !strcmp(m_p, s.m_p);
	//return (*this == s);//���ﲻ������ʹ�ã���Ϊ��δ����
}

bool my_string::operator!=(const my_string& s){

	return !(*this == s);

}

int my_string::operator<(const char *p) {

	return strcmp(p, this->m_p);
}
int my_string::operator>(const char *p) {

	return strcmp(this->m_p,p);
}
int my_string::operator<(const my_string& s) {

	return strcmp(s.m_p,this->m_p);
}
int my_string::operator>(const my_string& s) {

	return strcmp(this->m_p, s.m_p);

}