#include <stdio.h>

void Power(int num){
    if (num % 2 !=0){
        printf("%d����\n",num);
    }else{
        int tmp=num;
        while(num!=1){
            num/=2;
        }
        printf("%d��\n",tmp);
    }
}

int main(){
    int n=0;
    printf("������һ������n:");
    scanf("%d",&n);
    Power(n);
    return 0;
}
