#include <stdio.h>

void FindNum(int* arr,int size,int* x,int* y){
    int num=0;
    int pos=0;
    for (int i = 0; i <size ; ++i) {
        num =num^arr[i];//���������������Ľ��
    }

    for (int i = 0; i <32 ; ++i) {
        if(((num>>i)&1)==1){
            pos=i;//����num�ĵ�һ��Ϊ1�ı���λ
            break;
        }
    }
    for(int i = 0 ; i < size ; ++i){//�������
        if(((arr[i] >> pos)&1)==1){//��posλ��1������һ��,�������
            *x=*x^arr[i];
        }else {//��posλ��0������һ��,�������
            *y=*y^arr[i];
        }
    }
}
int main(){
    int arr[]={1,3,5,7,1,3,5,2};
    int size= sizeof(arr)/ sizeof(arr[0]);
    int x=0;
    int y=0;
    FindNum(arr,size,&x,&y);
    printf("����ֻ����һ�ε����ֱַ�Ϊ:%d %d\n",x,y);
}

#if 0
//һ��������������ֻ������һ��
int main(){
    int num=0;
    int arr[]={1,3,5,7,1,3,5};
    int size= sizeof(arr)/ sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        num=num^arr[i];
    }
    if(num!=0){
        printf("���������:%d\n",num);
    }
    return 0;
}
#endif