#include<stdio.h>
#include<stdlib.h>

int main(){

	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[] = { 9, 10, 11, 12, 13, 14, 15, 16 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	for (i = 0; i < len; i++){//判定下标

		int tmp = arr1[i];//tmp开始储存arr1中的第0,1,2,3,4,5,6,7号元素
		arr1[i] = arr2[i];//arr1中的元素按顺序被替换为arr2的元素,下标对应
		arr2[i] = tmp;//arr2中的元素按顺序被替换为arr1的元素
	}
	for (i = 0; i < len; i++){

		printf("%d ", arr1[i]);//按下表顺序依次打印替换后的arr1
	}
	printf("\n");
	for (i = 0; i < len; i++){

		printf("%d ", arr2[i]);//按下标顺序依次打印被替换后的arr2
	}
	printf("\n");
	system("pause");
	return 0;
}