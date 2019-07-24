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
    printf("������k��ֵ:");
    scanf("%d", &k);
    Rotate(arr, arr+len);//��ת�����ַ���
    Rotate(arr, arr + len-k);//��ת����Ҫ�������ַ�
    Rotate(arr+len-k+1, arr + len);//�����������ַ�˳��
    printf("��������ַ���Ϊ:");
    printf("%s\n", arr);
    system("pause");
    return 0;
}//
// Created by 28943 on 2019/7/24.
//

