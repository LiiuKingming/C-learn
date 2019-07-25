#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100

void Rotate(char* start, char* end){
    while (start < end){
        *start = *start ^ *end;
        *end = *start ^ *end;
        *start = *start ^ *end;
        ++start;
        --end;
    }
}

void left_rotate(char* str,int k){
    int len=strlen(str);
    Rotate(str,str+len-1);
    //旋转所有字符
    Rotate(str,str+len-1-k);
    //翻转所有无需旋转的字符
}

int is_rotate(char* s1,char*s2) {

    if (strlen(s1)!=strlen(s2)) {
        return 0;
        //判断两个字符串的长度,若不相等则直接返回0;
    }
    if (0==strcmp(s1, s2)) {
        return 1;
    }
    int k = strlen(s1);

    while (k>0) {
        left_rotate(s1, 1);
        if (0==strcmp(s1, s2)) {
            return 1;
        }
        k--;
    }
    return 0;
}


int main(){
    char s1[MAX] = { 0 };
    char s2[MAX] = { 0 };
    printf("请输入第一组字符串(5个字符):");
    scanf("%s", &s1);
    printf("请输入第二组字符串(5个字符):");
    scanf("%s", &s2);
    printf("%d\n",is_rotate(s1,s2));

    return 0;

}


