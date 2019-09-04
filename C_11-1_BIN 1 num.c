#include <stdio.h>
#include <stdlib.h>
//方法二:按位与操作计数
int BitOneCount(int num){//这种方法加不加unsigned都可以实现负数的
    int count = 0;
    for (int i = 0; i < 32; i++){//0-31,所以是i<32
        if ((num&(1 << i) )!= 0){
            ++count;
        }
    }return count;

}
//方法一:求模,不断移位判断数字奇偶来确定二进制代码中1的个数
int count_one_bits(unsigned int value) {//这种方法不加unsigned无法求负数,负数的二进制截断后会被理解成一个很大的数
    int count = 0;
    while (value != 0){
        if (value % 2 == 1){
            ++count;
        }
        value = value >> 1;// 或者num/=2，右位移1等于除以2
    }
    return count;
}
int main(){
    int ret1 = count_one_bits(-15);
    printf("ret=%d\n", ret1);
    int ret2 = BitOneCount(-10);
    printf("ret=%d\n", ret2);

    system("pause");
    return 0;
}//
// Created by 28943 on 2019/7/27.
//

