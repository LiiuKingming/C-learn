#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int Factorial(int n){
	if (n != 1){
		return Factorial(n -1)*n;
	}
	return 1;
	
}

int main(){
	int i = 0;
	int ret = 1;
	int result = 1;
	int n = 0;
	printf("«Î ‰»În:");
	scanf("%d", &n);
	result = Factorial(n);
	printf("%d\n", result);
	for (int i = 1; i <= n; i++){
		ret = ret*i;
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}