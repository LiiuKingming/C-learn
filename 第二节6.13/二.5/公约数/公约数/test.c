#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 24;
	int b = 18;
	int c = 0;//����

	while (a%b != 0){
		c = a%b;//����
		a = b;//��������Ϊ��һ�εĳ���
		b = c;//������Ϊ��һ�εı�����
	}
	printf("%d\n", c);

	system("pause");
	return 0;
}