#include <stdio.h>
#include <stdlib.h>

void init(int *arr,int size){
	printf("初始化后的数组:");
	for (int i = 0; i < size; i += 1){
		arr[i] = i;
		printf("%d ", arr[i]);
	}printf("\n");
}
void empty(int *arr, int size){
	printf("清零后的数组:");
	for (int i = 0; i < size; i += 1){
		arr[i] = 0;
		printf("%d ", arr[i]);
	}printf("\n");
}
void reverse(int *arr, int size){
	printf("逆置后的数组:");
	int arr1[10] = { 0 };
	for (int i=0; i < size; i += 1){
		p[i] = arr[i];
	}
	for (int i = 0; i < size; i ++ ){
		arr[i] = p[size - 1 - i];
		printf("%d ", arr[i]);
	}	printf("\n");
}

int main(){

	/*实现函数init（）初始化数组、 
	实现empty（）清空数组、
	实现reverse（）函数完成数组元素的逆置。*/
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int size;
	size = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, size);
	empty(arr, size);
	init(arr, size);
	system("pause");
	return 0;
}