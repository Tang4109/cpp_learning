/****************************************!
*@brief  
*@author ZhangYunjia
*@date   2019/5/8/13:50

****************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define CFGNAME "c:/book/mycfg.ini"


//显示菜单
void menu() {
	printf("=================================\n");
	printf("1 测试写配置文件\n");
	printf("2 测试读配置文件\n");
	printf("0 退出\n");
	printf("=================================\n");
}

//读配置项
int test_GetCfg() {

	int ret = 0;
	int value_len = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	printf("\n请键入key: ");
	scanf("%s", name);

	ret = GetCfgItem(CFGNAME, name,value, &value_len);
	
	if (ret != 0) {
		printf("func GetCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("value:%s\n", value);
	return ret;
}
//写配置项
//循环读每一行，检查key值是否存在，若存在则修改对应的value值
//若不存在，在文件末尾添加新数据
int test_WriteCfg() {
	int ret = 0;
	char name[1024] = { 0 };
	char value[1024] = { 0 };
	printf("\n请键入key: ");
	scanf("%s", name);

	printf("\n请键入value: ");
	scanf("%s", value);

	ret = WriteCfgItem(CFGNAME, name, value, strlen(value));
	if (ret != 0) {
		printf("func WriteCfgItem() err:%d\n", ret);
		return ret;
	}
	printf("你的输入时：%s=%s\n", name, value);
	return ret;
}

int main()
{
	int choice;

	for (;;) {
		//入口选择
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://写配置项
			test_WriteCfg();
			break;
		case 2://读配置项
			test_GetCfg();
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}

	}
	
	printf("end...\n");
	system("pause");
	return 0;
}