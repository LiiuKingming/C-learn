#include<stdio.h>
#if 0
int main(){

	int a = 5;
	int b = 3;
	a = a - b;//�������������Ĳ�ֵ,������һ������;
	b = b + a;//�ڶ���������ֵ���ϲ�ֵ�õ���һ��������ԭֵ,�����ڶ�������;
	a = b - a;//��һ��������ԭֵ��ȥ��ֵ�õ��ڶ���������ԭֵ,������һ������;
	
	printf("%d\n%d\n", a, b);

	system("pause");
	return 0;
}
#endif

int main()
{
	int a = 7;
	int b = 2;

	/*int tmp = a;
	a = b;
	b = tmp;*/

	//a = a+b;//a = 10+20 = 30
	//b = a-b;//30-20 = 10   b
	//a = a-b;//30-10 = 20    a
	//
	a = a ^ b;//0111 ^ 0010  = 0101
	b = a ^b;//0101 ^  0010 =  0111  =  7
	a = a ^ b;//0101 ^ 0111 = 0010    = 2
	printf("%d,%d\n", a, b);
	system("pause");
	return 0;

}
