#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
    int to_guess = rand() % 100 + 1;//随机生成一个数求其与100的余数,加一得到数范围为[1,101)
    while (1){
        printf("请输入您的猜测:");//让用户猜一个数字
        int num = 0;
        scanf("%d",&num);//读取用户的输入
        if (num < to_guess){
            printf("猜低了,往高猜猜!\n\n");
        }
        else if (num> to_guess){
            printf("猜高了,往低猜猜!\n\n");
        }
        else{
            printf("猜对了!\n");
            break;
        }
    }
}
int main(){
    srand((unsigned int)time(0));
    while (1){
        int choice = Menu();
        //读取用户选项
        if (choice == 1){
            Game();
        }
        else if (choice == 0){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("您的输入有误!\n");
        }
    }
    return 0;
}
