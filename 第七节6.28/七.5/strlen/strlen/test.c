#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int Strlen(char* n){
	int count = 0;
	while (*n != '\0'){
		count++;
		*n++;
	}return count;
}
int MyStrlen(char *n){
	if (*n == '\0')
	{
		return 0;
	}
	return 1 + MyStrlen(n + 1);
}
int main(){
	char n[] = { 0 };
	int ret = 0;
	printf("ÇëÊäÈë×Ö·û´®:");
	scanf("%s", n);
	ret = MyStrlen(n );
	printf("%d\n", ret);
	system("pause");
	return 0;
}