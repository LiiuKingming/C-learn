#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu(){
    printf("======================\n");
    printf("1.��ʼһ����Ϸ\n");
    printf("0.�˳�\n");
    printf("======================\n");
    printf("����������ѡ��:\n");
    int choice = 0;
    scanf("%d", &choice);
    return choice;
}
void Game(){
    int to_guess = rand() % 100 + 1;//�������һ����������100������,��һ�õ�����ΧΪ[1,101)
    while (1){
        printf("���������Ĳ²�:");//���û���һ������
        int num = 0;
        scanf("%d",&num);//��ȡ�û�������
        if (num < to_guess){
            printf("�µ���,���߲²�!\n\n");
        }
        else if (num> to_guess){
            printf("�¸���,���Ͳ²�!\n\n");
        }
        else{
            printf("�¶���!\n");
            break;
        }
    }
}
int main(){
    srand((unsigned int)time(0));
    while (1){
        int choice = Menu();
        //��ȡ�û�ѡ��
        if (choice == 1){
            Game();
        }
        else if (choice == 0){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("������������!\n");
        }
    }
    return 0;
}
