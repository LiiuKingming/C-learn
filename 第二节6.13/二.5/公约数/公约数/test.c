#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 24;
	int b = 18;
	int c = 0;//余数

	while (a%b != 0){
		c = a%b;//余数
		a = b;//被除数变为下一次的除数
		b = c;//余数变为下一次的被除数
	}
	printf("%d\n", c);

	system("pause");
	return 0;
}