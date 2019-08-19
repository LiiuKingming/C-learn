#include <stdio.h>

int main(){
    for (int b=1; b <= 9; b++){
        for (int a=1; a<= b; a++){
            printf("%d*%d=%d", a, b, a*b);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}