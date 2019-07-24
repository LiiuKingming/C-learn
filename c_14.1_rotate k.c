#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Rotate(char* start, char* end){
    int count = 0;
    while (start < end){
        *start = *start^*end;
        *end = *start^*end;
        *start = *start^*end;
        ++start;
        --end;
        count++;
    }
}

int main(){
    char arr[] = "ABCD";
    int len=strlen(arr)-1;
    int k = 0;
    printf("请输入k的值:");
    scanf("%d", &k);
    Rotate(arr, arr+len);//翻转整个字符数组
    Rotate(arr, arr + len-k);//将不参与左旋的字符顺序倒置
    Rotate(arr+len-k+1, arr + len);//调整参与左旋的字符的顺序
    printf("左旋后的字符串为:");
    printf("%s\n", arr);
    system("pause");
    return 0;
}//
// Created by 28943 on 2019/7/24.
//

