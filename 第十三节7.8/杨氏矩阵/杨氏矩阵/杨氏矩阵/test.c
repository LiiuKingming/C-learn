#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define row 3
#define col 3

int find_num(int arr[row][col], int num){
	int i = 0;
	int j = col-1;
	while (1){
		int tmp = arr[i][j];
		if (num == tmp){//先和矩阵右上角的数进行比较
			return 1;
		}
		else if (tmp < num && j >= 0){
			tmp = arr[i++][j];
		}
		else if(tmp > num && j>=0){
			tmp = arr[i][j--];
		}
		else{
			return 0;
		}
	}
}

int main(){
	int Young[row][col] = { 1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			printf("%d ", Young[i][j]);
		}
		printf("\n");
	}
	printf("请输入一个数字:");
	int num = 0;
	scanf("%d", &num);
	if (find_num(Young, num)){
		printf("%d在数组中\n", num);
	}
	else {
		printf("%d不在数组中\n", num);
	}

	system("pause");
	return 0;
}