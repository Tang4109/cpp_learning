/****************************************!
*@brief  面向抽象类编程（面向预先定义好的接口编程）-模块划分
*@author ZhangYunjia
*@date   2019/5/2/10:24

****************************************/

#include<iostream>

using namespace std;

class abstract { //抽象类
public:
	virtual void get_area() = 0;//纯虚函数
};

class circle :public abstract{
private:
	int r;

public:
	circle(int r_) {
		this->r = r_;
	}
	virtual void get_area() {
		cout << "圆的面积：" << 3.14*r*r << endl;
	}

};

class triangle :public abstract{
private:
	int a;
	int b;

public:
	triangle(int a_, int b_) {
		this->a = a_;
		this->b = b_;

	}
	virtual void get_area() {
		cout << "三角形的面积：" << 0.5*a*b << endl;
	}

};

class square :public abstract{
private:
	int a;
	int b;

public:
	square(int a_, int b_) {
		this->a = a_;
		this->b = b_;

	}
	virtual void get_area() {
		cout << "四边形的面积：" << a*b << endl;
	}

};

void print(abstract &base) {
	base.get_area();//多态
}


int main()
{
	//abstract a;//抽象类不能被实例化
	
	abstract *base = NULL;//ok
	circle c1(10);
	print(c1); 

	triangle t1(20, 30);
	print(t1);

	square s1(50, 60);
	print(s1);


	cout<<"end.."<<endl;
	system("pause");
	return 0;
}