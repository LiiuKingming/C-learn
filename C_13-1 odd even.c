#include <stdio.h>

int main(){
    int a[10] = { 0 };
    int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("请输入一组数字(10个):");
    for (int i = 0; i < 10; ++i){
        scanf("%d", &a[i]);
    }
    for (int i=0; i < 10; ++i){
        for (int j = i+1; j < 10; ++j){
            if (a[i] % 2 == 0 && a[j] % 2 != 0){
                int tmp = 0;
                tmp=a[i];
                a[i] = a[j];
                a[j] = tmp;

            }
        }
    }
    for (int i = 0; i < 10; ++i){
        printf("%d\n", a[i]);
    }
    return 0;
}//
// Created by 28943 on 2019/7/28.
//

