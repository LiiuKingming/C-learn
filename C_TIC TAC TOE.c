#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 3
#define MAX_COL 3

void Init(char board[MAX_ROW][MAX_COL]){
    for (int row = 0; row < MAX_ROW; ++row){
        for (int col = 0; col < MAX_COL; ++col){
            board[row][col] = ' ';
        }
    }
    srand(time(NULL));
}

void Print(char board[MAX_ROW][MAX_COL]){
    printf(" ---|---|---\n");
    for (int row = 0; row < MAX_ROW; ++row){
        printf("| %c | %c | %c |\n",
               board[row][0], board[row][1], board[row][2]);
        printf(" ---|---|---\n");
    }
}

void PlayMove(char board[MAX_ROW][MAX_COL]){
    while (1){
        printf("请输入坐标(row col):\n");
        int row = 0;
        int col = 0;
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
            printf("您的输入有误!\n");
            continue;
        }
        if (board[row][col]!=' '){
            printf("这个位置已经有子了,请重新落子!\n");
            continue;
        }
        board[row][col] = 'x';
        break;
    }
}

void ComputerMove(char board[MAX_ROW][MAX_COL]){
    while (1){
        int row = rand() % MAX_ROW;
        int col = rand() % MAX_COL;
        if (board[row][col] != ' '){
            continue;
        }
        board[row][col] = 'o';
        break;
    }
}
int IsFull(char board[MAX_ROW][MAX_COL]){
    for (int row = 0; row < MAX_ROW; ++row){
        for (int col = 0; col < MAX_COL; ++col){
            if (board[row][col] == ' '){
                return 0;
            }//棋盘没有满返回0
        }
    }
    return 1;
}

char IsWin(char board[MAX_ROW][MAX_COL]){
    for (int row = 0; row < MAX_ROW; ++row){
        if (board[row][0] == board[row][1]
            && board[row][0] == board[row][2]
            && board[row][0] != ' '){
            return board[row][0];
        }
    }
    for (int col = 0; col < MAX_COL; ++col){
        if (board[0][col] == board[1][col]
            && board[0][col] == board[2][col]
            && board[0][col] != ' '){
            return board[0][col];
        }
    }
    if (board[0][0]==board[1][1]
        &&board[0][0]==board[2][2]
        &&board[0][0]!=' '){
        return board[0][0];
    }
    if (board[0][2] == board[1][1]
        && board[0][2] == board[2][0]
        &&board[0][2] != ' '){
        return board[0][2];
    }
    if (IsFull(board)){
        return '=';
    }
    return ' ';
}

int main(){

    char chess_board[MAX_ROW][MAX_COL];
    Init(chess_board);
    char result = ' ';
    while (1){
        Print(chess_board);
        PlayMove(chess_board);
        result = IsWin(chess_board);
        if (result != ' '){
            break;
        }
        ComputerMove(chess_board);
        result = IsWin(chess_board);//判定游戏是否结束
        if (result != ' '){
            break;
        }
    }
    if (result == 'x'){
        Print(chess_board);
        printf("Winner!\n");
    }
    else if (result == 'o'){
        Print(chess_board);
        printf("Loser!\n");
    }
    else{
        Print(chess_board);
        printf("卢本伟牛逼!\n");
    }
    system("pause");
    return 0;
}//
// Created by 28943 on 2019/7/27.
//

