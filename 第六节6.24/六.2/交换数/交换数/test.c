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
	printf("请输入第一个数a:");
	scanf("%d", &a);
	printf("请输入第二个数b:");
	scanf("%d", &b);
	exchange(&a, &b);
	printf("交换后a=%d\n", a);
	printf("交换后b=%d\n", b);
	system("pause");
	return 0;
}