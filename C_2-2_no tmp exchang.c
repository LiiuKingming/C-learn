#include<stdio.h>

int main()
{
    int a = 7;
    int b = 2;

    /*int tmp = a;
    a = b;
    b = tmp;*/

    /*a = a+b;//a = 10+20 = 30
    //b = a-b;//30-20 = 10   b
    //a = a-b;//30-10 = 20    a */
    a = a ^ b;//0111 ^ 0010  = 0101
    b = a ^b;//0101 ^  0010 =  0111  =  7
    a = a ^ b;//0101 ^ 0111 = 0010    = 2
    printf("%d,%d\n", a, b);
    return 0;
}
#if 0
int main(){

	int a = 5;
	int b = 3;
	a = a - b;//计算两个变量的差值,赋给第一个变量;
	b = b + a;//第二个变量的值加上差值得到第一个变量的原值,赋给第二个变量;
	a = b - a;//第一个变量的原值减去差值得到第二个变量的原值,赋给第一个变量;

	printf("%d\n%d\n", a, b);

	system("pause");
	return 0;
}
#endif
