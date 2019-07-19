#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void PrintNum(unsigned int num){//无符号 unsingned int
	if (num > 9){//多位数
		PrintNum(num / 10);
	}
	printf("%d ", num % 10);
}
void print(int num){

	if (num != 0){
		printf("%d", num%10);
		num=num / 10;
	}

}
int main(){
	int num = 0;
	printf("请输入一个数字:");
	scanf("%d", &num);
	printf("\n");
	PrintNum(num);
	print(num);

	system("pause");
	return 0;
}