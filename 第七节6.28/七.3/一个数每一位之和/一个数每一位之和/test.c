#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int DigitSum(unsigned int num){//�޷��� unsingned int
	if (num > 9){//��λ��
		return DigitSum(num / 10) + num%10;
	}
	return num;
}
int main(){
	int n = 0;
	int ret = 0;
	printf("������һ������:");
	scanf("%d", &n);
	printf("\n");
	ret=DigitSum(n);
	printf("%d \n", ret);
	system("pause");
	return 0;
}