#include<stdio.h>

int main(){
    int a = 9;
    int b = 0;
    int c = 10;
    //a>=b>=c
    if (a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a <c){
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c){
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d,%d,%d\n", a, b, c);//10,9,0
    return 0;
}