#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main(){
	int ch;
	while ((ch = getchar()) != EOF){
		if (ch >= 'a'&&ch <= 'z'){
			putchar(ch - 32);
		}
		if (ch >= 'A'&&ch <= 'Z'){
			putchar(ch +32);
		}if (ch >= '0' && ch <= '9')
		{
		}
	}

	system("pause");
	return 0;
}

#if 0
int main(){
	char input[20] ;
	printf("ÇëÊäÈë:");
	scanf("%s", input);
	for (unsigned int i = 0; i < strlen(input); i++){
		if (input[i] >= 'a'&& input[i] <= 'z'){
			input[i] = input[i] - 32;
			printf("%s", input[i]);
		}
		if (input[i] >= 'A' && input[i] <= 'Z'){
			input[i] = input[i] + 32;
			printf("%s", input[i]);
		}
	}
	system("pause");
	return 0;
}
#endif
