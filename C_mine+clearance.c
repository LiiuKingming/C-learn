#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

//创建两个二维数组来表示地图
//(1). show_map 表示给玩家展示的内容(数字表示翻开,表示未翻开)
//(2). mine_map 表示地雷的布局(0不是地雷,!是地雷)
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_ROWS 11
#define MAX_COLS 11
#define MINE_COUNT 10

void Init(char show_map[MAX_ROWS][MAX_COLS],
          char mine_map[MAX_ROWS][MAX_COLS]){
    srand((unsigned int)time(NULL));
    //1.对于show_map 初始化为全'*'
    for (int row = 0; row <= MAX_ROWS; ++row){
        for (int col = 0; col <= MAX_COLS; ++col){
            show_map[row][col] = '*';
        }
    }
    //2.对于mine_map来说,先初始化全为0,在随机生成若干个地雷
    for (int row = 0; row <= MAX_ROWS; ++row){
        for (int col = 0; col <= MAX_COLS; ++col){
            mine_map[row][col] = '0' ;
        }
    }
    int count = MINE_COUNT;
    while (count!=0){
        int row = (rand()%MAX_ROW+1);
        int col = (rand()%MAX_COL+1);
        if (mine_map[row][col] == '1'){//这个位置已经是雷了,重新生成一个雷
            continue;//进入下次循环
        }
        mine_map[row][col] = '1';
        --count;
    }
}
void PrintMap(char map[MAX_ROWS][MAX_COLS]){
    //1.先打印顶部行号
    printf("  | ");
    for (int col = 1; col <= MAX_COL; ++col){
        printf("%d  " , col);
    }
    printf("\n");
    //2.打印一排分割线
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
        printf("请输入一组坐标x,y:");
        //scanf的参数是一个指针类型的变量
        //此时此刻row和col本来就是指针int,就不用再&
        scanf("%d,%d", row, col);
        //合法性判定
        if (*row <= 0|| *row > MAX_ROW||
            *col <= 0|| *col > MAX_COL){
            printf("您的输入有误,请重新输入!\n");
            continue;
        }
        if (show_map[*row][*col] != '*'){
            //当前位置已经被翻开就需要重新输入坐标
            printf("您输入的坐标已经被翻开,请输入新的坐标!\n");
            continue;
        }
        break;
    }
}

//判定当前位置周围雷的数目
int cal_mine(char mine_map[MAX_ROWS][MAX_COLS],int row,int col){
    return (mine_map[row - 1][col - 1] + mine_map[row - 1][col] +mine_map[row - 1][col + 1]
        + mine_map[row][col-1]+mine_map[row][col + 1]
        + mine_map[row + 1][col-1]+mine_map[row + 1][col] + mine_map[row + 1][col+1]
        - (7 * '0') );//这里减7而不是8。因为这样直接可以表示出数字字符
        //此处的目的是统计周围雷的个数，又因为是ASCII码，'1'和'0'只相差1，然后进去’0'的ASCII值得到1的个数
}
void Expand(char mine_map[MAX_COLS][MAX_COLS],
            char show_map[MAX_ROWS][MAX_COLS], int row, int col){
    if (row >= 1 && row <= MAX_ROW&&col >= 1 && col <= MAX_COL){// 递归防止越界
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
    //核心流程
    //1.创建地图并初始化
    //a)show_map,初始化为全为
    //b)mine_map,要随机生成若干个雷(10个)
    char show_map[MAX_ROWS][MAX_COLS];
    char mine_map[MAX_ROWS][MAX_COLS];
    Init(show_map, mine_map);
    while (1){
        //TODO 打印mine_map方便调试临时加入,调试完去掉
        PrintMap(mine_map);
        //2.打印地图
        printf("================================\n");
        PrintMap(show_map);
        //3.都区玩家输入的坐标,并校验(要过滤非法坐标)
        int row=0;
        int col=0;
        GetPos(show_map, &row, &col);
        //4.尝试翻开对应的坐标
        //a)翻开的坐标是地雷,游戏失败
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
        }//判断期盼中'*'的个数,如果等于地雷数则判定游戏获胜
        // 5.循环进行 2,while循环
    }
}
int main(){
    srand((unsigned int)time(NULL));
    printf(" 欢 ");Sleep(100);
    printf(" 迎 ");Sleep(100);
    printf(" 进 ");Sleep(100);
    printf(" 入 ");Sleep(100);
    printf(" 扫 ");Sleep(100);
    printf(" 雷 ");Sleep(100);
    printf(" 游 ");Sleep(100);
    printf(" 戏 ");Sleep(100);
    printf(" ! \n");Sleep(300);
    printf("*******************************************\n");
    printf("              |------------|              \n");
    printf("--------------   想要开始吗?  --------------\n");
    printf("              |------------|               \n");
    printf("---------------  1.直接开始!  --------------\n");
    printf("              |------------|               \n");
    printf("---------------  0. 溜了！    --------------\n");
    printf("              |------------|          \n");
    printf("*******************************************\n");
    printf("宝贝说句话啊?\n");
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

