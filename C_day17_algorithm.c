#include <stdio.h>

void find(int arr[],int k,int size){
    int mid=arr[(0+size)/2-1];
    for (int i = 0; i <=mid ; ++i) {
        int tmp=k-arr[i];
        for (int j = mid; j <size ; ++j) {
            if(arr[j]==tmp){
                printf("�ҵ�%d+%d=%d,����ֱ�Ϊ%d��%d\n",arr[i],arr[j],k,i,j);
            }
        }
    }
}

int main(){
    int k=0;
    printf("����������k:");
    scanf("%d",&k);
    int arr[]={1,2,3,4,5,6,7,8,9,10,11};
    int size= sizeof(arr)/ sizeof(arr[0]);
    find(arr,k,size);
    return 0;
}
