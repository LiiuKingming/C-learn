#include <stdio.h>

void palindrome(int num){
    int tmp=num;
    int flip=0;
    while(num!=0){
        flip=flip*10+(num % 10);
        num /= 10;
    }
    if(flip==tmp){
        printf("%d是回文数\n",tmp);
    }else{
        printf("%d不是回文数\n",tmp);
    }

}
int main(){
    int num=0;
    printf("请输入一个整数:");
    scanf("%d",&num);
    palindrome(num);
    return 0;
}