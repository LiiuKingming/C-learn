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
    system("pause");
    return 0;
}