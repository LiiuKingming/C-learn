#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	char password[] = "123456";//设置一个密码
	int i = 0;
	int count = 3;
	for (; i < count; i += 1){
		printf("请输入密码:\n");
		char input[100] = { 0 };
		scanf("%s", input);//引导用户输入密码
		if (strcmp(password, input) == 0){//通过比较数组是否相同,判断密码是否正确,
			printf("登录成功!\n");
			break;//密码正确则跳出循环
		}
		else{
			printf("密码错误,你还有%d次机会\n",count-i-1);
		}
	}if (i == 3){
		printf("密码错误次数达到三次,登陆失败\n");//判定输入错误的次数
	}
	system("pause");
	return 0;
}