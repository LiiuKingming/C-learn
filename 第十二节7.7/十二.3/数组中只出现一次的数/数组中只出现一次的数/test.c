#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[5] = { 0 };
	printf("请输入一组数字(5个):");
	for (int i = 0; i < 5; i++){
		scanf("%d", &arr[i]);
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	int tmp = 0;
	printf("单独出现的数字有:");
	
	for (int i = 0; i < size; i++){
		tmp = arr[i];
		int count = 0;
		for (int j = 0; j < size; j++){
			if ((tmp^arr[j]) == 0){
				count++;
			}
		}
		if (count<2){
			printf("%d ", tmp);
		}
	}
	system("pause");
	return 0;
}


#if 0
int main()
{
	int arr[15] = { 0 };
	int i = 0;
	int count = 0;
	printf("请输入15个以内的数字，按CTRL+z结束");
	while (EOF != scanf("%d", &arr[i]))
	{
		count++;  //记录用户输入数字的个数
		i++;
	}
	i = 0;
	int final = 0;
	while (count)
	{
		final = final^arr[i]; //任何数与0相与或都为他本身
		i++;
		count--;
	}
	if (0 == final)
	{
		printf("成对出现\n");
	}
	else
	{
		printf("不成对\n");
	}
	system("pause");

	return 0;
}
#endif
