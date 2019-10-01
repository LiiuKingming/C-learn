//
// Created by 28943 on 2019/9/29.
//
#include <stdio.h>
#include <string.h>

size_t MyStrlen(const char* str){
    size_t len = 0;
    for(;str[len] != 0; ++len){
        //循环体中不需要其他代码了
    }
    return len;
}

int main(){
    char* str = "hehe";
    int len = MyStrlen(str);
    printf("%d\n" , len);
    return 0;
}
