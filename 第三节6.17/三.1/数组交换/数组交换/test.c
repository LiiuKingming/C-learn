#include<stdio.h>
#include<stdlib.h>

int main(){

	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[] = { 9, 10, 11, 12, 13, 14, 15, 16 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	for (i = 0; i < len; i++){//�ж��±�

		int tmp = arr1[i];//tmp��ʼ����arr1�еĵ�0,1,2,3,4,5,6,7��Ԫ��
		arr1[i] = arr2[i];//arr1�е�Ԫ�ذ�˳���滻Ϊarr2��Ԫ��,�±��Ӧ
		arr2[i] = tmp;//arr2�е�Ԫ�ذ�˳���滻Ϊarr1��Ԫ��
	}
	for (i = 0; i < len; i++){

		printf("%d ", arr1[i]);//���±�˳�����δ�ӡ�滻���arr1
	}
	printf("\n");
	for (i = 0; i < len; i++){

		printf("%d ", arr2[i]);//���±�˳�����δ�ӡ���滻���arr2
	}
	printf("\n");
	system("pause");
	return 0;
}