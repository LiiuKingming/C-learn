#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

int Menu(){
	printf("======================\n");
	printf("1.开始一局游戏\n");
	printf("0.退出\n");
	printf("======================\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int to_guess = rand() % 100 + 1;//随机生成一个数求其与100的余数,加一得到数范围为1-100.
	while (1){
		printf("请输入您的猜测:%d");//让用户猜一个数字
		int num = 0;
		scanf("%d", num);//读取用户的输入
		if (num < to_guess){
			printf("低了!\n");
		}
		else if (num> to_guess){
			printf("高了!\n");
		}
		else{
			printf("猜对了!\n");
			break;
		}
	}
}
int main(){
	while (1){
		int choice = Menu();
		if (choice = 1){
			Game();
		}
		else if (choice = 0){
			printf("Goodbye!\n");
		}
		else{
			printf("您的输入有误!\n");
			break;
		}
	}	system("pause");
	return 0;
}

