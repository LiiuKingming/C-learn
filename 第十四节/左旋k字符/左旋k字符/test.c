#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Rotate(char* start, char* end){
	int count = 0;
	while (start < end){
		*start = *start^*end;
		*end = *start^*end; 
		*start = *start^*end;
		++start;
		--end;
		count++;
	}
}

int main(){
	char arr[] = "ABCD";
	int len=strlen(arr)-1;
	int k = 0;
	printf("��������Ҫ���ü����ַ�:");
	scanf("%d", &k);
	Rotate(arr, arr+len);//��һ���������ַ�������
	Rotate(arr, arr + len-k);//���������������ַ������û���
	Rotate(arr+len-k+1, arr + len);//�����ò����������ַ���˳��
	printf("���ú���ַ���Ϊ:");
	printf("%s\n", arr);
	system("pause");
	return 0;
}