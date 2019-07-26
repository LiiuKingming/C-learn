#include <stdio.h>
#include<stdlib.h>
#include <time.h>

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
        if (mine_map[row][col] == '!'){//这个位置已经是雷了,重新生成一个雷
            continue;//进入下次循环
        }
        mine_map[row][col] = '!';
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
        printf("请输入一组坐标:");
        //scanf的参数是一个指针类型的变量
        //此时此刻row和col本来就是指针int,就不用再&
        scanf("%d %d", row, col);
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
//判定当前位置周围雷的数目,并更新对应的地图位置
void UpdateMap(char show_map[MAX_ROWS][MAX_COLS],
               char mine_map[MAX_ROWS][MAX_COLS],
               int row,int col){
    int mine_count = 0;
    //1,周围八个位置有几个雷
    //2,把这个数字更新到show_map中
    //int mine_count = 0;
    //row一定在[0,MAX_ROW)
    //row - 1一定小于MAX_ROW
    //左上
    if (row-1>=0&&col-1>=0
                       &&mine_map[row - 1][col - 1] == '!'){
        ++mine_count;
    }
    //正上
    if (row - 1 > 0
                  && mine_map[row - 1][col] == '!'){
        ++mine_count;
    }
    //右上
    if (row - 1 > 0 && col + 1 < MAX_COL
                                && mine_map[row - 1][col + 1] == '!'){
        ++mine_count;
    }
    //正左
    if ( col - 1 >= 0
                   && mine_map[row][col - 1] == '!'){
        ++mine_count;
    }
    //正右
    if (col + 1 < MAX_COL
                 && mine_map[row][col +1] == '!'){
        ++mine_count;
    }
    //左下
    if (row + 1< MAX_ROW && col - 1 >= 0
                                     && mine_map[row + 1][col - 1] == '!'){
        ++mine_count;
    }
    //正下
    if (row+ 1 < MAX_ROW
               && mine_map[row +1][col] == '!'){
        ++mine_count;
    }
    //右下
    if (row + 1 < MAX_ROW && col + 1 < MAX_COL
                                   && mine_map[row + 1][col + 1] == '!'){
        ++mine_count;
    }
    //2.把这个数更新到show_map中
    //字符也是用数字来表示的,ascii码表
    //要把这个数字转成对应的字符
    show_map[row][col] = mine_count + '0';
}

void Game(){
    //核心流程
    //1.创建地图并初始化
    //a)show_map,初始化为全为
    //b)mine_map,要随机生成若干个雷(10个)
    char show_map[MAX_ROWS][MAX_COLS];
    char mine_map[MAX_ROWS][MAX_COLS];
    Init(show_map, mine_map);
    //2.打印地图
    int safe_count = 0;
    while (1){
        //TODO 打印mine_map方便调试临时加入,调试完去掉
        PrintMap(mine_map);
        printf("================================\n");
        PrintMap(show_map);
        //3.都区玩家输入的坐标,并校验(要过滤非法坐标)
        int row=0;
        int col=0;
        GetPos(show_map, &row, &col);
        //4.尝试翻开对应的坐标
        //a)翻开的坐标是地雷,游戏失败
        if (mine_map[row][col] == '!'){
            PrintMap(mine_map);
            printf("Game Over!\n");
            break;
        }
        //b)翻开的坐标不是地雷,更新show_map,给当前位置显示一个数字
        ++safe_count;
        if (safe_count == MAX_ROW*MAX_COL - MINE_COUNT){
            printf("Victory!\n");
            break;
        }
        //c)翻开的坐标不是地雷,并且是最后一个不是地雷的格子,游戏获胜
        UpdateMap(show_map,mine_map,row,col);
       // 5.循环进行 2,while循环
    }
}


int main(){
    srand((unsigned int)time(NULL));
    Game();

    return 0;
}
//
// Created by 28943 on 2019/7/26.
//

