#include <stdio.h>
#include <stdlib.h>

//�ݹ�汾���ظ�����Ч�ʽϵͣ�
int fibonacci(int n){

    if(n==1 || n==2){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int Fibonacci(int n){
    //����f1��f2����������������f3���������
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    int i = 0;
    for(i = 3;i <= n;i++){
        f3 = f1+f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
int main(){
    int n=0;
    printf("������n:");
    scanf("%d", &n);
    int ret = Fibonacci(n);
    printf("%d\n",ret);
    system("pause");
    return 0;
}
#if 0//�Լ�д�Ĵ����
int Fibonacci(n){
	if (n != 1 || n != 2){
		return 1;
	}
	return Fibonacci(n - 1)*n;
}
int main(){
	int n = 0;
	int ret = 0;
	printf("������n��ֵ:");
	scanf("%d", &n);
	ret = Fibonacci(n);
	system("pause");
	return 0;
}
#endif
