#include <stdio.h>

int Maxsum(int arr[],int size){
    if(arr==NULL||size==0){//非法判定
        return -1;
    }
    int sum=0;
    int i=0;
    int max=arr[i];
    for (; i < size; ++i) {
        sum = sum + arr[i];
        if (sum < arr[i]) {//若当前数字比更新前的sum更大则舍弃之前的和,从当前数字开始累加
            sum = arr[i];
        }

        if (max < sum) {//如果更新的和大于之前的最大值,则更新最大值
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

