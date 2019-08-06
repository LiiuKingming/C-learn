#include <stdio.h>
#include <stdlib.h>

//递归版本（重复计算效率较低）
int fibonacci(int n){

    if(n==1 || n==2){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int Fibonacci(int n){
    //设置f1和f2保存最深两层数，f3储存更新数
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
    printf("请输入n:");
    scanf("%d", &n);
    int ret = Fibonacci(n);
    printf("%d\n",ret);
    system("pause");
    return 0;
}
#if 0//自己写的错代码
int Fibonacci(n){
	if (n != 1 || n != 2){
		return 1;
	}
	return Fibonacci(n - 1)*n;
}
int main(){
	int n = 0;
	int ret = 0;
	printf("请输入n的值:");
	scanf("%d", &n);
	ret = Fibonacci(n);
	system("pause");
	return 0;
}
#endif
