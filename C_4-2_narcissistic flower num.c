#include<stdio.h>

int main(){
    int a;
    int b;
    int c;
    int num;
    printf("ˮ�ɻ����ֱ�Ϊ:\n");
    for (num = 100; num < 1000; num += 1){
        //ˮ�ɻ�������λ��,���Դ�100��ʼ
        c = num / 100;//��λ
        b = (num - 100 * c) / 10;//ʮλ
        a = num - 100 * c - 10 * b;//��λ
        if (c*c*c + b*b*b + a*a*a == num){
            //�ж���num�Ƿ����ˮ�ɻ���������
            printf("%d\n", num);
        }
    }
    return 0;
}
#if 0

//��Ҫ#include<math.h>

int main(){
	
	int i = 0;
	for (i = 0; i <= 999999; i++){
		int count = 0;//���ֵ�λ��
		int tmp = i;
		int sum = 0;
		while (tmp != 0){
			count++;
			tmp = tmp / 10;
		}
		//i�Ǽ�λ���Ѿ����count  
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