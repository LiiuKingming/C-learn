#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[5] = { 0 };
	printf("������һ������(5��):");
	for (int i = 0; i < 5; i++){
		scanf("%d", &arr[i]);
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	int tmp = 0;
	printf("�������ֵ�������:");
	
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
	printf("������15�����ڵ����֣���CTRL+z����");
	while (EOF != scanf("%d", &arr[i]))
	{
		count++;  //��¼�û��������ֵĸ���
		i++;
	}
	i = 0;
	int final = 0;
	while (count)
	{
		final = final^arr[i]; //�κ�����0�����Ϊ������
		i++;
		count--;
	}
	if (0 == final)
	{
		printf("�ɶԳ���\n");
	}
	else
	{
		printf("���ɶ�\n");
	}
	system("pause");

	return 0;
}
#endif
