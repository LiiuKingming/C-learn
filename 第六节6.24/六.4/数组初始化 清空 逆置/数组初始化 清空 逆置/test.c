#include <stdio.h>
#include <stdlib.h>

void init(int *arr,int size){
	printf("��ʼ���������:");
	for (int i = 0; i < size; i += 1){
		arr[i] = i;
		printf("%d ", arr[i]);
	}printf("\n");
}
void empty(int *arr, int size){
	printf("����������:");
	for (int i = 0; i < size; i += 1){
		arr[i] = 0;
		printf("%d ", arr[i]);
	}printf("\n");
}
void reverse(int *arr, int size){
	printf("���ú������:");
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

	/*ʵ�ֺ���init������ʼ�����顢 
	ʵ��empty����������顢
	ʵ��reverse���������������Ԫ�ص����á�*/
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	int size;
	size = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, size);
	empty(arr, size);
	init(arr, size);
	system("pause");
	return 0;
}