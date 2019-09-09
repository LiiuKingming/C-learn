#include <stdio.h>

void Power(int num){
    if (num % 2 !=0){
        printf("%d不是\n",num);
    }else{
        int tmp=num;
        while(num!=1){
            num/=2;
        }
        printf("%d是\n",tmp);
    }
}

int main(){
    int n=0;
    printf("请输入一个数字n:");
    scanf("%d",&n);
    Power(n);
    return 0;
}
