#include <stdio.h>

//��ĿҪ���ҳ��ַ����е�һ��ֻ����һ�ε��ַ�,��ʱ�临�Ӷ�ΪO(n)
//��һ�ַ���ʱ�临�Ӷ�ΪO(n*n),������Ҫ��
int FindChar1(char arr[],int size) {
    for (int i = 0; i <size ; ++i) {
        int count=0;
        for (int j = 0; j <size ; ++j) {
            while(i==j){
                ++j;
            }
            if(arr[i]==arr[j]){
                ++count;
                break;
            }
        }
        if(count==0){
            printf("%c\n",arr[i]);
            return  0;
        }
    }
}

int FindChar(char* p,int size){
    if(p==NULL){
        return -1;
    }
    int arr1[256]={0};//��ʼ��һ������
    char* q=p;
    while(*q !='\0'){//���ֵ��ַ�,��ascii���ӦΪ��arr1�е��±�,ÿ����һ�θ�Ԫ�ؼ�1,
        arr1[*q]++;
        q++;
    }
    q=p;
    while ( *q !='\0'){
        if(arr1[*q]==1){
            return *q;
        }
        q++;
    }
}
int main(){
    char arr[]="abgbacdcdffe";
    int size= sizeof(arr)/ sizeof(arr[0]);
    printf("%c",FindChar(arr,size));
    return 0;
}



