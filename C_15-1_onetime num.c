#include <stdio.h>

void FindNum(int* arr,int size,int* x,int* y){
    int num=0;
    int pos=0;
    for (int i = 0; i <size ; ++i) {
        num =num^arr[i];//储存所有数字异或的结果
    }

    for (int i = 0; i <32 ; ++i) {
        if(((num>>i)&1)==1){
            pos=i;//储存num的第一个为1的比特位
            break;
        }
    }
    for(int i = 0 ; i < size ; ++i){//分组异或
        if(((arr[i] >> pos)&1)==1){//第pos位是1的数字一组,进行异或
            *x=*x^arr[i];
        }else {//第pos位是0的数字一组,进行异或
            *y=*y^arr[i];
        }
    }
}
int main(){
    int arr[]={1,3,5,7,1,3,5,2};
    int size= sizeof(arr)/ sizeof(arr[0]);
    int x=0;
    int y=0;
    FindNum(arr,size,&x,&y);
    printf("两个只出现一次的数字分别为:%d %d\n",x,y);
}

#if 0
//一个数字在数组中只出现了一次
int main(){
    int num=0;
    int arr[]={1,3,5,7,1,3,5};
    int size= sizeof(arr)/ sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        num=num^arr[i];
    }
    if(num!=0){
        printf("这个数字是:%d\n",num);
    }
    return 0;
}
#endif