#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* reverse_string(char* str){
	int len = strlen(str);
	if (len > 1) {
		char temp;
		temp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = temp;
	}
	return str;
}
int main(){
	char str[10] = { 0 };
	char ch;
	printf("������һ���ַ���(10���ַ�����,�Ի��з���ֹ):");
	for (int i = 0; i < 10; i++) {
		if ((ch = getchar()) != '\n') {
			str[i] = ch;
			continue;
		}
		break;
	}
	printf("�ַ���Ԫ��Ϊ:\t");
	puts(str);
	reverse_string(str);
	printf("�������Ϊ:\t");
	puts(str);
	system("pause");
	return 0;
}
