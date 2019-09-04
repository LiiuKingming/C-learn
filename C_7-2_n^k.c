#include <stdio.h>

int Pow(int n,int k){
    if (k == 0){
        return 1;
    }
    return n*Pow(n,k-1);
}
int main(){
    int n = 0;
    int k = 0;
    int ret = 0;
    printf("请输入n k:");
    scanf("%d %d", &n,&k );
    ret = Pow(n,k);
    printf("%d\n",ret);
    return 0;
}
