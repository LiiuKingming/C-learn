#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int exchange(int* x,int* y){ 
	int tmp;
	tmp= *x;
	*x = *y;
	*y = tmp;
	return *x;
	return *y;
}
int main(){
	int a=0;
	int b=0;
	printf("�������һ����a:");
	scanf("%d", &a);
	printf("������ڶ�����b:");
	scanf("%d", &b);
	exchange(&a, &b);
	printf("������a=%d\n", a);
	printf("������b=%d\n", b);
	system("pause");
	return 0;
}