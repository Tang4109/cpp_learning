/****************************************!
*@brief  多态案例
*@author ZhangYunjia
*@date   2019/4/30/14:33

****************************************/

#include<iostream>

using namespace std;

class hero_fighter
{
public:
	virtual int power() {
		return 10;
	}

};

class enemy_fighter {
public:
	int attack() {
		return 15;
	}

};

class adv_hero_fighter:public hero_fighter {
public:
	virtual int power() {
		return 20;
	}


};
//多态
void main_test(hero_fighter *hf,enemy_fighter *ef) {// hf 定义父类指针，可以指向子类
	if (hf->power() > ef->attack())
	{
		cout << "hero win." << endl;
	}
	else {
		cout << "hero defeat." << endl;

	}

}


int main()
{
	hero_fighter hf;
	adv_hero_fighter adv_hf;
	enemy_fighter ef;

	main_test(&hf, &ef);
	main_test(&adv_hf, &ef);

	cout<<"end.."<<endl;
	system("pause");
	return 0;
}