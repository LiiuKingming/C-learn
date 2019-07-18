#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

void leap_year(){
	int year;
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		printf("这是闰年.\n");
	}
	else{
		printf("这不是闰年.\n");
	}
}

int main(){
	int year=0;
	printf("请输入想查询的年份:");
	leap_year(year);
	system("pause");
	return 0;
}