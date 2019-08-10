#include <stdio.h>


void Swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void BubbleSort(int* arr, int size){//每次找最小的方式,[0,bound)已排序区间,[bound,size)待排序区间
    for (int bound = 0; bound < size; ++bound){//这个循环每执行一次,bound就增加1,此时就找到了一个比较小的值,并放到合适的位置
        for (int cur = size - 1; cur>bound; --cur){//不写cur>0可以少检测很多已经排好的数,完成一趟之中的找最小的过程,从后往前找
            if (arr[cur - 1] > arr[cur]){//cur+1下标越界,此处是升序排序,如果前一个元素比后一个元素大,那就交换两个函数
                Swap(&arr[cur - 1], &arr[cur]);
            }
        }
    }
}
int main(){

    int arr[4] = { 9, 5, 2, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, size);
    for (int i = 0; i < size; ++i){
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
