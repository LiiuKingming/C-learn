#include <stdio.h>

void palindrome(int num){
    int tmp=num;
    int flip=0;
    while(num!=0){
        flip=flip*10+(num % 10);
        num /= 10;
    }
    if(flip==tmp){
        printf("%d�ǻ�����\n",tmp);
    }else{
        printf("%d���ǻ�����\n",tmp);
    }

}
int main(){
    int num=0;
    printf("������һ������:");
    scanf("%d",&num);
    palindrome(num);
    return 0;
}