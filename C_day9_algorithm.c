#include <stdio.h>

int Maxsum(int arr[],int size){
    if(arr==NULL||size==0){//�Ƿ��ж�
        return -1;
    }
    int sum=0;
    int i=0;
    int max=arr[i];
    for (; i < size; ++i) {
        sum = sum + arr[i];
        if (sum < arr[i]) {//����ǰ���ֱȸ���ǰ��sum����������֮ǰ�ĺ�,�ӵ�ǰ���ֿ�ʼ�ۼ�
            sum = arr[i];
        }

        if (max < sum) {//������µĺʹ���֮ǰ�����ֵ,��������ֵ
            max = sum;
        }
    }
    return max;
}

int main(){
    int arr[]={1,-2,3,10,-4,7,2,-5};
    int size= sizeof(arr)/ sizeof(arr[0]);
    printf("%d\n",Maxsum(arr,size));
    return 0;
}

