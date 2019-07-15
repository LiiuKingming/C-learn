#if 0
#include<stdio.h>
int main(){
	int n;
	int s;
	for (n = 1; n <= 7; n++){//前七行星数递增
		for (s = 1; s <= 2 * n - 1; s++){//星数每次加2
			printf("*");

		}printf("\n");
	}
	for (n = 7; n <= 13;n++){//从第八行开始后六行星数递减
		for (s = 1; s <= 11 - 2 * (n - 7); s++){//星数每次减2
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif
#include<stdio.h>
int main(){
	int n
	int s;
	for (n = 0; n < 7; n++){
		for (s = 1; s <= 2 * n - 1; s++){
			printf("*");

		}printf("\n");
	}
	for (n = 7; n <= 13; n++){
		for (s = 1; s <= 11 - 2 * (n - 7); s++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
