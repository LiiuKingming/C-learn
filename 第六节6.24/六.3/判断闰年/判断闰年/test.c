#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

void leap_year(){
	int year;
	scanf("%d", &year);
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		printf("��������.\n");
	}
	else{
		printf("�ⲻ������.\n");
	}
}

int main(){
	int year=0;
	printf("���������ѯ�����:");
	leap_year(year);
	system("pause");
	return 0;
}