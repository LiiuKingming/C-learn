#include<stdio.h>

int main(){
    int year=1000;
    for (; year <= 2000; year += 1){
        if (year % 4 == 0 && year % 100 != 0){
            printf("%d������ͨ����\n", year);
        }
        else if(year%400==0){
            printf("%d������������\n", year);

        }
    }
    return 0;
}
