#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int Average(int a, int b){
	int tmp = (a&b) + ((a^b) >> 1);
	return tmp;
}

int main(){
	printf("����������a b:");
	int ret = 0;
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	ret = Average(a, b);
	printf("a��b��ƽ����Ϊ:%d\n", ret);
	system("pause");
	return 0;
}