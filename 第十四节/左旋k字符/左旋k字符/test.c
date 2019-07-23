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
	printf("请输入需要倒置几个字符:");
	scanf("%d", &k);
	Rotate(arr, arr+len);//第一步将整个字符串倒置
	Rotate(arr, arr + len-k);//将不参与左旋的字符串倒置回来
	Rotate(arr+len-k+1, arr + len);//调整好参与左旋的字符的顺序
	printf("倒置后的字符串为:");
	printf("%s\n", arr);
	system("pause");
	return 0;
}