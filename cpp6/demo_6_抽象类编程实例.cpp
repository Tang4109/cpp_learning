/****************************************!
*@brief  �����స��
*@author ZhangYunjia
*@date   2019/5/2/15:21

****************************************/

#include<iostream>

using namespace std;

class programmer { //������
public:
	virtual void get_salary() = 0;//���麯��
};

class junior_programmer :public programmer{
private:
	const char *name;
	const char *job;
	int salary;

public:
	junior_programmer(const char *name_, const char *job_,int salary_) {
		this->name=name_;
		this->job = job_;
		this->salary = salary_;
	}
	virtual void get_salary() {
		cout << "������" << name << " ���֣�" << job << " н�ʣ�" << salary << endl;
	}

};

class mid_programmer :public programmer {
private:
	const char *name;
	const char *job;
	int salary;

public:
	mid_programmer(const char *name_, const char *job_, int salary_) {
		this->name = name_;
		this->job = job_;
		this->salary = salary_;
	}
	virtual void get_salary() {
		cout << "������" << name << " ���֣�" << job << " н�ʣ�" << salary << endl;
	}

};

class high_programmer :public programmer {
private:
	const char *name;
	const char *job;
	int salary;

public:
	high_programmer(const char *name_, const char *job_, int salary_) {
		this->name = name_;
		this->job = job_;
		this->salary = salary_;
	}
	virtual void get_salary() {
		cout << "������" << name << " ���֣�" << job << " н�ʣ�" << salary << endl;
	}

};

class architect :public programmer {
private:
	const char *name;
	const char *job;
	int salary;

public:
	architect(const char *name_, const char *job_, int salary_) {
		this->name = name_;
		this->job = job_;
		this->salary = salary_;
	}
	virtual void get_salary() {
		cout << "������" << name << " ���֣�" << job << " н�ʣ�" << salary << endl;
	}

};



void print_salary(programmer &base) {
	base.get_salary();//��̬
}


int main()
{
	//abstract a;//�����಻�ܱ�ʵ����

	programmer *base = NULL;//ok

	junior_programmer p("zyj", "java", 20000); 
	print_salary(p);

	mid_programmer p2("zrf", "python", 30000);
	print_salary(p2);

	high_programmer p3("xhh", "c++", 50000);
	print_salary(p3);

	architect p4("ljh", "html", 60000);
	print_salary(p4);

	//cout << "end.." << endl;
	system("pause");
	return 1;
}