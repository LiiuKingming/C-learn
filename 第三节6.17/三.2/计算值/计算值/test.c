//题目看错了
#if 0
#include  <stdio.h>
int main(){
	float b = 2;
	float c = 1;
	for (b; b <= 100; b++){

		c = c - (1 / b);
		
	}
	printf("%f\n", c);
	system("pause");
	return 0;
}
#endif
//1/1-1/2+1/3...+1/99
#include<stdio.h>
#include<stdlib.h>
int main(){
	double sum = 0;
	int i = 0;
	int flg = 1;
	for (i = 1; i <= 100; i++){
		sum = sum + flg*(1.0 / i);
		flg = -flg;
	}
	printf("%f\n", sum);

	system("pause");
	return 0;
}


