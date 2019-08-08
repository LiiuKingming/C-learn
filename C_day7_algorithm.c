#include <stdio.h>


void k_num(int* arr,int size,int num){
    for (int bound = 0; bound < size; ++bound) {
        for (int cur = size-1; cur >bound ; --cur) {
            if(arr[cur-1]>arr[cur]){
                arr[cur-1]=arr[cur-1]^arr[cur];
                arr[cur]=arr[cur-1]^arr[cur];
                arr[cur-1]=arr[cur-1]^arr[cur];
            }
        }
    }
    for (int k = 0; k <num ; ++k) {
        printf("%d ",arr[k]);
    }
}

int main(){
    int arr[9]={9,8,7,6,5,4,3,2,1};
    int size= sizeof(arr)/ sizeof(arr[0]);
    int k=0;
    scanf("%d",&k);
    if (k<=size) {
        k_num(arr, size, k);
    }
    return 0;
}