#include<stdio.h>

int main(){
    int a;
    int b;
    int c;
    int num;
    printf("水仙花数分别为:\n");
    for (num = 100; num < 1000; num += 1){
        //水仙花数是三位数,所以从100开始
        c = num / 100;//百位
        b = (num - 100 * c) / 10;//十位
        a = num - 100 * c - 10 * b;//个位
        if (c*c*c + b*b*b + a*a*a == num){
            //判断数num是否符合水仙花数的条件
            printf("%d\n", num);
        }
    }
    return 0;
}
#if 0

//需要#include<math.h>

int main(){
	
	int i = 0;
	for (i = 0; i <= 999999; i++){
		int count = 0;//数字的位数
		int tmp = i;
		int sum = 0;
		while (tmp != 0){
			count++;
			tmp = tmp / 10;
		}
		//i是几位数已经求得count  
		//123 123%10=3  123/10=12   12%10 2
		// 12/10=1  1%10 1    1/10=0
		tmp = i;
		while (tmp != 0){
			sum = sum + pow((double)(tmp % 10), count);
			tmp /= 10;//12  12/10 1 1/10=0
		}
		if (sum == i){
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
#endif