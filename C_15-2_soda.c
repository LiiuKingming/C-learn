#include <stdio.h>

int BuySoda(int soda){
    static int bottle=0;
    if(soda*2+bottle<2){//�ж��Ƿ���ʣ��һ����ƿ
        return 0;
    }
    if(soda%2==0){//���п�ƿ�һ���ˮ
        return soda+BuySoda(soda/2);
    }else if(soda%2==1 &&bottle==0){//��ƿ�һ���ʣ��һ��ƿ��
        bottle++;
        return soda+BuySoda(soda/2);
    }else if(soda%2==1 && bottle==1){//��ƿ�һ���ʣһ��,��ǰʣһ���պü������һ�һƿ��ˮ
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
