//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void mul(int n){

	for (int a = 1; a <= n; a += 1){
		for (int b = 1; b <= a; b += 1){
			printf("%d*%d=%d", a, b, a*b);
			printf(" ");
		}printf("\n");
	}
}

int main(){
	int a=0;
	int b=0;
	printf("������˷���������:");
	int n = 0;
	scanf("%d", &n);
	mul(n);
	system("pause");
	return 0;
}