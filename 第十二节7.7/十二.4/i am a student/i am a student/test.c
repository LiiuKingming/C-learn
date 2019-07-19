#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* arr){
	int len = 0;
	while (*arr++){//当数组元素不为'\0'时++len,
		//arr的首元素地址进行++来判断arr的元素内容,使用++*str会越界
		++len;
	}
	return len;
}
void reverse(char* start, char* end){
	//当左下标小于右下标时交换两个数
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
	//先对整个字符串进行逆置
	reverse(arr, arr + my_strlen(arr) - 1);
	printf("%s\n", arr);
	//再对每个单词进行逆置
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
	//整个字符串的倒置一开始想了很久,发现太复杂了留个纪念
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
