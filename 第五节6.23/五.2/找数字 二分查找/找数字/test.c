#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[], int key, int left, int right){
	int mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] > key){
			right = mid - 1;
		}
		else if (arr[mid] < key){
		    left = mid + 1;
		}
		else if (arr[mid] = key){
			return mid;
			break;
		}
	}
	while (left > right){
		printf("找不到!");
	}
}
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = binarySearch(arr, 7, 0, size - 1);
	printf("下标为:%d\n", ret);
	system("pause");
	return 0;
}
#if 0;
int main(){
	int num = 8;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = size - 1;
	while (left <= right){
		int mid = (left + right) / 2;//折半查找
		if (num < arr[mid]){
			right = mid - 1;
		}
		else if (num>arr[mid]){
			left = mid + 1;
		}
		else{
			printf("找到了,下标为%d\n", mid);
			break;
		}
	}if (left > right){

		printf("-1\n,");
	}
	system("pause");
	return 0;
}
#endif