#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 5

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
	char s1[MAX] = { 0 };
	char s2[MAX] = { 0 };
	printf("请输入第一组字符串(5个字符):");
	for (int i = 0; i < MAX; ++i){
		scanf("%c", &s1[i]);
	}
	printf("请输入第二组字符串(5个字符):");
	for (int i = 0; i < MAX; ++i){
		scanf("%c", &s2[i]);
	}

	int len = strlen(s1);
	int count = 0;
	while (count < len){
		Rotate(s1, s1 + len);
		Rotate(s1, s1 + len - 1);
		count++;
		int strcmp(s1, s2);
		if (strcmp(s1, s2) == 0){
			break;
		}
		else{
			continue;
		}
	}
	if (count = 5){
		return 0;
	}
	else{
		return count;
	}
	system("pause");
	return 0;
}