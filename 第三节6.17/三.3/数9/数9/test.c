#include<stdio.h>
int main(){
	int a;
	int num = 1;
	for (a = 1; a <= 100; a++){
		if (a % 10 == 9){
			num++;
			printf("%d\n", a);
		}
		else if (a / 10 == 9){
			num++;

			printf("%d\n", a);
		}
		
	}printf("个数num=%d\n", num);
	//99当中有两个9
	system("pause");
	return 0;
}