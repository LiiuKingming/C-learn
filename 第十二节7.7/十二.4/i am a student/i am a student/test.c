#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* arr){
	int len = 0;
	while (*arr++){//������Ԫ�ز�Ϊ'\0'ʱ++len,
		//arr����Ԫ�ص�ַ����++���ж�arr��Ԫ������,ʹ��++*str��Խ��
		++len;
	}
	return len;
}
void reverse(char* start, char* end){
	//�����±�С�����±�ʱ����������
	while (start < end){
		*start = *start^ *end;
		*end = *start^ *end;
		*start = *start^ *end;
		++start;
		--end;
	}
}

int main(){
	char arr[] = "student a am I";
	printf("%s\n", arr);
	char* left = arr;
	char* right = arr;
	//�ȶ������ַ�����������
	reverse(arr, arr + my_strlen(arr) - 1);
	printf("%s\n", arr);
	//�ٶ�ÿ�����ʽ�������
	while (*left != '\0'&& *right != '\0'){
		if (*right == ' '){
			reverse(left, right - 1);
			left = right + 1;
		}
		right++;
	}
	reverse(left, right - 1);
	printf("%s\n", arr);

	system("pause");
	return 0;
}
#if 0
int main(){
	//�����ַ����ĵ���һ��ʼ���˺ܾ�,����̫��������������
	char arr[] = "student a am i";
	printf("%s\n", arr);
	char tmp[15] = { 0 };
	int my_strlen = (sizeof(arr) / sizeof(arr[0])) - 1;//14
	for (int i = my_strlen - 1; i >= 0; --i){//13
		if (arr[i + 1] == '\0'){
			int a = (my_strlen - 1) - i;
			tmp[a] = arr[i];
			arr[i] = '\0';
		}
	}
	for (int i = 0; i < my_strlen; i++){
		arr[i] = tmp[i];
	}
	printf("%s\n", arr);
	return 0;
}
#endif
