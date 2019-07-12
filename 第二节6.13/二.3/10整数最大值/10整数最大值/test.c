#include<stdio.h>
#include<stdlib.h>

int main(){

	int n = 0;
	int a[] = {1,4,3,6,2,5,8,10,9,8};
	int big = a[0];
	int len = sizeof(a) / sizeof(a[0]);//数组字节数
	//sizeof(a):整个数组字节数40;
	//sizeof(a[0]):4;
	for (n = 1; n <= 9; n += 1){
		if (big < a[n])
			big = a[n];
	}
	printf("最大的数是:%d\n", big);

	system("pause");
	return 0;
}