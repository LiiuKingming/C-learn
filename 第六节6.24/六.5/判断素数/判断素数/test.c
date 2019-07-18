#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime_num(num){
	num = 0;
	int i = 2;
	scanf("%d", &num);
	for (i = 2; i <= sqrt((double)num); i += 1){
		if (num%i == 0){
			printf("%d不是素数\n", num);
			break;
		}
	}if (i >= sqrt((double)num)){
		printf("%d是素数\n", num);
	}
}

int main(){
	int num=0;
	printf("请输入要判断的数字:");
	prime_num(num);
	system("pause");
	return 0;
}