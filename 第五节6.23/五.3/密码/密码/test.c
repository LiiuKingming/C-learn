#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	char password[] = "123456";//����һ������
	int i = 0;
	int count = 3;
	for (; i < count; i += 1){
		printf("����������:\n");
		char input[100] = { 0 };
		scanf("%s", input);//�����û���������
		if (strcmp(password, input) == 0){//ͨ���Ƚ������Ƿ���ͬ,�ж������Ƿ���ȷ,
			printf("��¼�ɹ�!\n");
			break;//������ȷ������ѭ��
		}
		else{
			printf("�������,�㻹��%d�λ���\n",count-i-1);
		}
	}if (i == 3){
		printf("�����������ﵽ����,��½ʧ��\n");//�ж��������Ĵ���
	}
	system("pause");
	return 0;
}