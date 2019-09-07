#include <stdio.h>

int BuySoda(int soda){
    static int bottle=0;
    if(soda*2+bottle<2){//判断是否有剩下一个空瓶
        return 0;
    }
    if(soda%2==0){//所有空瓶兑换汽水
        return soda+BuySoda(soda/2);
    }else if(soda%2==1 &&bottle==0){//空瓶兑换完剩下一个瓶子
        bottle++;
        return soda+BuySoda(soda/2);
    }else if(soda%2==1 && bottle==1){//空瓶兑换完剩一个,此前剩一个刚好加起来兑换一瓶汽水
        bottle--;
        return soda+BuySoda(soda/2+1);
    }
}

int main(){
    int money=20;
    int num=BuySoda(money);
    printf("%d\n",num);
    return 0;
}
