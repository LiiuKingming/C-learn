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
		
	}printf("����num=%d\n", num);
	//99����������9
	system("pause");
	return 0;
}