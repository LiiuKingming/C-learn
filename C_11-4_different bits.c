#include <stdio.h>
#include <stdlib.h>

void Function(int m, int n){
    int i = 0;
    int count = 0;
    for (i =31; i >=0; i--){
        if (((m >> i)&1) != ((n >> i)&1)){
            count++;
        }
    }
    printf("%d\n", count);
}

int main(){
    Function(1999,2299);
    int a=0;
    int b=0;
    int size=sizeof(b=a-2);
    printf("%d\n",size);
    return 0;
}