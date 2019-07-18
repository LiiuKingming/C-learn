//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void mul(int n){

	for (int a = 1; a <= n; a += 1){
		for (int b = 1; b <= a; b += 1){
			printf("%d*%d=%d", a, b, a*b);
			printf(" ");
		}printf("\n");
	}
}

int main(){
	int a=0;
	int b=0;
	printf("请输入乘法表行列数:");
	int n = 0;
	scanf("%d", &n);
	mul(n);
	system("pause");
	return 0;
}