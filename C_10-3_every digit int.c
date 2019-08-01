#include<stdio.h>
#include <stdlib.h>

int Print(unsigned int num){
    if (num > 9){
        Print(num/10);
    }
    printf("%d ", num%10);
}
int main(){
    Print(1234);
    system("pause");
    return 0;
}
