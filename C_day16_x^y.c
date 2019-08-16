#include <stdio.h>

int Pow(int x,int y){
    if(y==0){
        return 1;
    }
    return x*Pow(x,y-1);
}

int main(){
    int x=0;
    int y=0;
    printf("ÇëÊäÈëx,y:");
    scanf("%d,%d",&x,&y);
    int ret=Pow(x,y);
    printf("%d\n",ret);
    return 0;
}
