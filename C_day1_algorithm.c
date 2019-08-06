#include <stdio.h>
#include <stdlib.h>

#define row 4
#define col 4

int find_num(int arr[row][col],int num) {
    int i = 0;
    int j = col - 1;
    int tmp=arr[i][j];
    while (1) {
        if (num == tmp) {
            return 1;
        }
        else if (num > tmp&&j>=0) {
            tmp=arr[i++][j];
        }
        else if(num<tmp&&j>=0){
            tmp=arr[i][j--];
        }else{
            return 0;
        }
    }
}

int main() {
    int a[row][col ] = {
            1, 2, 8, 9,
            2, 4, 9, 12,
            4, 7, 10, 13,
            6, 8, 11, 15};

    int num = 0;
    printf("������Ҫ�ҵ�����:");
    scanf("%d", &num);

    if(find_num(a,num)) {
        printf("�ҵ�%d��\n",num);
    }else{
        printf("�Ҳ���%d\n",num);
    }
    return 0;
}

// Created by 28943 on 2019/8/5.
//

