#include<stdio.h>
#include<stdlib.h>

int main(){

	int n = 0;
	int a[] = {1,4,3,6,2,5,8,10,9,8};
	int big = a[0];
	int len = sizeof(a) / sizeof(a[0]);//�����ֽ���
	//sizeof(a):���������ֽ���40;
	//sizeof(a[0]):4;
	for (n = 1; n <= 9; n += 1){
		if (big < a[n])
			big = a[n];
	}
	printf("��������:%d\n", big);

	system("pause");
	return 0;
}