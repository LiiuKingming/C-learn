#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

//����������ά��������ʾ��ͼ
//(1). show_map ��ʾ�����չʾ������(���ֱ�ʾ����,��ʾδ����)
//(2). mine_map ��ʾ���׵Ĳ���(0���ǵ���,!�ǵ���)
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_ROWS 11
#define MAX_COLS 11
#define MINE_COUNT 10

void Init(char show_map[MAX_ROWS][MAX_COLS],
          char mine_map[MAX_ROWS][MAX_COLS]){
    srand((unsigned int)time(NULL));
    //1.����show_map ��ʼ��Ϊȫ'*'
    for (int row = 0; row <= MAX_ROWS; ++row){
        for (int col = 0; col <= MAX_COLS; ++col){
            show_map[row][col] = '*';
        }
    }
    //2.����mine_map��˵,�ȳ�ʼ��ȫΪ0,������������ɸ�����
    for (int row = 0; row <= MAX_ROWS; ++row){
        for (int col = 0; col <= MAX_COLS; ++col){
            mine_map[row][col] = '0' ;
        }
    }
    int count = MINE_COUNT;
    while (count!=0){
        int row = (rand()%MAX_ROW+1);
        int col = (rand()%MAX_COL+1);
        if (mine_map[row][col] == '1'){//���λ���Ѿ�������,��������һ����
            continue;//�����´�ѭ��
        }
        mine_map[row][col] = '1';
        --count;
    }
}
void PrintMap(char map[MAX_ROWS][MAX_COLS]){
    //1.�ȴ�ӡ�����к�
    printf("  | ");
    for (int col = 1; col <= MAX_COL; ++col){
        printf("%d  " , col);
    }
    printf("\n");
    //2.��ӡһ�ŷָ���
    printf("----------------------------\n");
    for (int row = 1; row<= MAX_ROW; ++row){
        printf("%d |", row);
        for (int col = 1; col<=MAX_COL; ++col){
            printf(" %c " , map[row][col]);
        }
        printf("\n");
    }
}

void GetPos(char show_map[MAX_ROWS][MAX_COLS], int*row, int*col){
    while (1){
        printf("������һ������x,y:");
        //scanf�Ĳ�����һ��ָ�����͵ı���
        //��ʱ�˿�row��col��������ָ��int,�Ͳ�����&
        scanf("%d,%d", row, col);
        //�Ϸ����ж�
        if (*row <= 0|| *row > MAX_ROW||
            *col <= 0|| *col > MAX_COL){
            printf("������������,����������!\n");
            continue;
        }
        if (show_map[*row][*col] != '*'){
            //��ǰλ���Ѿ�����������Ҫ������������
            printf("������������Ѿ�������,�������µ�����!\n");
            continue;
        }
        break;
    }
}

//�ж���ǰλ����Χ�׵���Ŀ
int cal_mine(char mine_map[MAX_ROWS][MAX_COLS],int row,int col){
    return (mine_map[row - 1][col - 1] + mine_map[row - 1][col] +mine_map[row - 1][col + 1]
        + mine_map[row][col-1]+mine_map[row][col + 1]
        + mine_map[row + 1][col-1]+mine_map[row + 1][col] + mine_map[row + 1][col+1]
        - (7 * '0') );//�����7������8����Ϊ����ֱ�ӿ��Ա�ʾ�������ַ�
        //�˴���Ŀ����ͳ����Χ�׵ĸ���������Ϊ��ASCII�룬'1'��'0'ֻ���1��Ȼ���ȥ��0'��ASCIIֵ�õ�1�ĸ���
}
void Expand(char mine_map[MAX_COLS][MAX_COLS],
            char show_map[MAX_ROWS][MAX_COLS], int row, int col){
    if (row >= 1 && row <= MAX_ROW&&col >= 1 && col <= MAX_COL){// �ݹ��ֹԽ��
        if (mine_map[row][col] == '0'){
            char count = cal_mine(mine_map,row,col);
            if (count == '0'){
                show_map[row][col] = ' ';
                if (show_map[row - 1][col - 1] == '*'){
                    Expand(mine_map, show_map, row - 1, col - 1);
                }
                if (show_map[row - 1][col] == '*'){
                    Expand(mine_map, show_map, row - 1, col);
                }
                if (show_map[row - 1][col + 1] == '*'){
                    Expand(mine_map, show_map, row - 1, col + 1);
                }
                if (show_map[row][col - 1] == '*'){
                    Expand(mine_map, show_map, row, col - 1);
                }
                if (show_map[row][col + 1] == '*'){
                    Expand(mine_map, show_map, row, col + 1);
                }
                if (show_map[row + 1][col - 1] == '*'){
                    Expand(mine_map, show_map, row + 1, col - 1);
                }
                if (show_map[row + 1][col] == '*'){
                    Expand(mine_map, show_map, row + 1, col);
                }
                if (show_map[row + 1][col + 1] == '*'){
                    Expand(mine_map, show_map, row + 1, col + 1);
                }
            }
            else{
                show_map[row][col] = count;
            }
        }
    }
}

void Game(){
    //��������
    //1.������ͼ����ʼ��
    //a)show_map,��ʼ��ΪȫΪ
    //b)mine_map,Ҫ����������ɸ���(10��)
    char show_map[MAX_ROWS][MAX_COLS];
    char mine_map[MAX_ROWS][MAX_COLS];
    Init(show_map, mine_map);
    while (1){
        //TODO ��ӡmine_map���������ʱ����,������ȥ��
        PrintMap(mine_map);
        //2.��ӡ��ͼ
        printf("================================\n");
        PrintMap(show_map);
        //3.����������������,��У��(Ҫ���˷Ƿ�����)
        int row=0;
        int col=0;
        GetPos(show_map, &row, &col);
        //4.���Է�����Ӧ������
        //a)�����������ǵ���,��Ϸʧ��
        if (mine_map[row][col] == '1'){
            PrintMap(mine_map);
            printf("Game Over!\n");
            break;
        }
        else{
            Expand(mine_map,show_map,row,col);
        }

        int safe_count = 0;
        for (int row = 1; row <= MAX_ROW; ++row) {
            for (int col = 1; col <= MAX_COL; ++col) {
                if(show_map[row][col]=='*'){
                    safe_count++;
                }
            }
        }
        if (safe_count == MINE_COUNT){
            PrintMap(show_map);
            printf("Victory!\n");
            break;
        }//�ж�������'*'�ĸ���,������ڵ��������ж���Ϸ��ʤ
        // 5.ѭ������ 2,whileѭ��
    }
}
int main(){
    srand((unsigned int)time(NULL));
    printf(" �� ");Sleep(100);
    printf(" ӭ ");Sleep(100);
    printf(" �� ");Sleep(100);
    printf(" �� ");Sleep(100);
    printf(" ɨ ");Sleep(100);
    printf(" �� ");Sleep(100);
    printf(" �� ");Sleep(100);
    printf(" Ϸ ");Sleep(100);
    printf(" ! \n");Sleep(300);
    printf("*******************************************\n");
    printf("              |------------|              \n");
    printf("--------------   ��Ҫ��ʼ��?  --------------\n");
    printf("              |------------|               \n");
    printf("---------------  1.ֱ�ӿ�ʼ!  --------------\n");
    printf("              |------------|               \n");
    printf("---------------  0. ���ˣ�    --------------\n");
    printf("              |------------|          \n");
    printf("*******************************************\n");
    printf("����˵�仰��?\n");
    int num=0;
    do{
        scanf("%d",&num);
        switch (num){
            case 1:
                Game();
                break;
            case 0:
                return 0;
        }
    }while(num);
    Game();
    return 0;
}

