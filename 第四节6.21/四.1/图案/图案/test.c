#if 0
#include<stdio.h>
int main(){
	int n;
	int s;
	for (n = 1; n <= 7; n++){//ǰ������������
		for (s = 1; s <= 2 * n - 1; s++){//����ÿ�μ�2
			printf("*");

		}printf("\n");
	}
	for (n = 7; n <= 13;n++){//�ӵڰ��п�ʼ�����������ݼ�
		for (s = 1; s <= 11 - 2 * (n - 7); s++){//����ÿ�μ�2
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif
#include<stdio.h>
int main(){
	int n
	int s;
	for (n = 0; n < 7; n++){
		for (s = 1; s <= 2 * n - 1; s++){
			printf("*");

		}printf("\n");
	}
	for (n = 7; n <= 13; n++){
		for (s = 1; s <= 11 - 2 * (n - 7); s++){
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
