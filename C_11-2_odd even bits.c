#include <stdlib.h>
#include <stdio.h>

void Function(int num){
    int i = 0;
    for (i = 31; i >= 1; i = i - 2){
        printf("%d ",(num>>i) & 1);
    }
    printf("\n");
    for (i = 30; i >= 0; i = i - 2){
        printf("%d ", (num >> i) & 1);
    }
}
int main(){
    Function(10);
    system("pause");
    return 0;
}

