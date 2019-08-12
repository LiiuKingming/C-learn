#include <stdio.h>

int RepeatChar(char arr[],int size) {
    for (int i = 0; i <size ; ++i) {
        int count=0;
        for (int j = 0; j <size ; ++j) {
            while(i==j){
                ++j;
            }
            if(arr[i]==arr[j]){
                ++count;
                break;
            }
        }
        if(count==1){
            return  arr[i];
        }
    }
}

int main(){
    char arr[]="qywyer23tdd";
    int size= sizeof(arr)/ sizeof(arr[0]);
    printf("%c\n", RepeatChar(arr,size));
    return 0;
}