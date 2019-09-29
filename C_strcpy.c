//
// Created by 28943 on 2019/9/29.
//
#include <stdio.h>
#include <string.h>
#include <assert.h>


char* Strcpy(char* dest , const char* src){//des目标 src原字符串
    //函数实现者的角度来保证参数有效
    //只能一定程度的保证
    //参数校验是重要考点
    assert(src != NULL && dest != NULL);
    int i = 0;
    for (; src[i] != '\0' ; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int main(){
    char str1[100] = "hehe";
    char str2[100] = "hahaha";
    Strcpy(str1 , str2);
    printf("%s\n",str1);
    return 0;
}
