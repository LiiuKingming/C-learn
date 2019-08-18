#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int pri = 0;
    int n = 0;
    for (pri = 101; pri <= 200; pri += 2){
        for (n = 2; n <= sqrt((double)pri); n += 1){
            if (pri % n == 0){
                break;
            }
        }
        if (n >=sqrt((double)pri)){
            printf("%d\n", pri);
        }
    }
    system("pause");
    return 0;
}