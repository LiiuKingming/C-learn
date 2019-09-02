#include<stdio.h>
#include <string.h>

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
