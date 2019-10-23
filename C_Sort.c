//
// Created by 28943 on 2019/10/13.
//
#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void InsertSort(int* a , int n){
    //??????????
    //???: O(N^2)
    //???: O(1)
    //?????: ???
    //??????: ????????????, ??临?????????O(N)
    //         ????????????????? , ??临???O(N)
    assert(a);
    int i;
    for(i = 0;i < n-1 ;++i){
        //????????????
        //??????????????????????λ??
        int end = i;
        //??end + 1???λ??????????????λ??
        int tmp = a[end + 1];
        while(end >= 0 && a[end] > tmp){
            a[end + 1 ] = a[end];
            --end;
        }
        //????????λ??
        a[end + 1] = tmp;
    }
}

void Shell(int* a , int n){
    //???????
    //???: O(N^1.3 ~ N^2)
    //???: O(1);
    //????? : ?????
    int gap = n;//???
    int i;
//    for(; gap >= 1; gap -= num){//?????????
//        for (num = 0; num < gap ; ++num) {//??????????
    while(gap >1){
        //gap > 1 -->????????
        //gap = 1 -->???????
        gap = gap / 3 + 1;//+1??????????????????
        for(i = 0 ; i < n - gap ; i ++){
            int end = i;
            int tmp = a[end + gap];
            while(end >= 0 && a[end] > tmp){
                a[end + gap] = a[end];
                end -= gap;
            }
            a[end + gap] = tmp;
        }
    }
}
void Swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//???????
//???: O(N^2)
//???: O(1)
//?????: ?????>=???
void SelectSort(int* a, int n){
    int begin = 0 , end = n-1;
    while(begin < end){
        //??????????????С????, ????????λ??
        int i, max, min;
        max = min = begin;
        for(i = begin; i <= end; ++i){
            if(a[i] < a[min])
                min = i;
            if(a[i] >= a[max])
                max = i;
        }
        //min --> begin   max -->end
        Swap(&a[begin], &a[min]);
        //?ж?λ??????????
        if(max == begin)
            max = min;
        Swap(&a[end] , &a[max]);
        ++begin;
        --end;
    }

}

//???????,???????? O(logN)
void ShiftDown(int* a,int n,int root) {//???????n
    //(n - 2) / 2?????????????????
    // 0~(n - 2) / 2 ???з??????????
    assert(a);
    int parent = root;
    int child = 2 * parent + 1;
    //???????????child
    while (child < n) {
        //???????child,?????,???????????
        if (child + 1 < n && a[child + 1] > a[child])
            ++child;
        //child??????parent
        if (a[child] > a[parent]) {
            //????
            Swap(&a[child], &a[parent]);
            //????????ε?????λ??
            parent = child;
            child = 2 * parent + 1;
        } else {
            //??parent????????????????????,????????
            break;
        }
    }
}

void HeapSort(int* a, int n){
    //????
    //????????????? (n - 2) /2
    int i , end;
    for (i = (n - 2) / 2 ; i >= 0 ; --i) {
        ShiftDown(a , n , i );
    }
    //??????
    end = n - 1;
    while(end > 0){//????????????????
        Swap(&a[0], &a[end]);//????
        ShiftDown(a, end, 0);//???????????
        --end;//????? ??????????
    }
}

//???O(N ~ N^2)
//???: O(1)
//?????: ???
void BubbleSort(int* a, int n){
    int cur, bound;
    for(bound = n; bound > 0; --bound){
        int flag = 0;
        for(cur = 1; cur < bound; ++cur ){
            //?????ε??????????????????
            flag = 1;
            if(a[cur] < a[cur - 1]){
                Swap(&a[cur] , &a[cur - 1]);
            }
        }
        if(flag == 0)
            break;
    }
}

//三数取中法
int getMid(int* a, int left, int right){
    int mid = left + (right - left) / 2;
    if(a[mid] > a[left]){
        if(a[mid] < a[right]){
            return mid;
        }else{
            //mid >left, right
            if(a[left] > a[right]){
                return left;
            }else{
                return right;
            }
        }
    }else{
        //mid <= left
        if(a[left] < a[right]){
            return left;
        }else{
            //left >= right, mid
            if(a[mid] > a[right])
                return mid;
            else
                return right;
        }
    }
}

int PrevCurPointer(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    //最后一个小于key的位置
    int prev = left;
    //下一个小于key的位置
    int cur = left + 1;
    int key = a[left];
    while (cur <= right){
        //如果下一个小于key的位置与上一个小于key的位置不连续
        //说明中间有大于key的值, 进行交换, 大-->向后移动, 小<--向前移动
        if(a[cur]< key && ++prev != cur){//不连续
            Swap(&a[prev], &a[cur]);
        }
        ++cur;
    }
    Swap(&a[prev], &a[left]);
    return prev;
}

int Dig(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);
    int key = a[left];
    while (left < right){
        //从右边找小
        while (left > right && a[right] >= key){
            --right;
        }
        a[left] = a[right];
        //从左边找大的
        while (left < right && a[right] <= key)
            ++left;
        //填坑
        a[right] = a[left];
    }
    //存放key
    a[left] = key;
    return left;
}

//快排的一次排序:确定基准值的位置
int PartSort(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    int key = a[left];
    int start = left;
    //寻找大小元素交换
    while(left < right){
        //先从右边找小于key的值
        while(left < right && a[right] >= key)
            --right;
        //从左边找大于key的值
        while(left < right && a[left] <= key)
            ++left;
        Swap(&a[left], &a[right]);
    }
    //key的位置确定 : left right 相遇的位置
    Swap(&a[start], &a[left]);
    return left;
}
//空间: 空间可以复用 最大的递归调用链--> logN
//时间: N * logN
//序列有序 时间效率最差--> N^2
void QuickSort(int* a, int left, int right){
    if(left >= right)
        return;
        //小区间优化: 小区间不再调用递归
    else if(right - left + 1 < 5){
        InsertSort(a + left, right - left + 1);
    }else{
        int mid = PartSort(a, left, right);
        QuickSort(a, left, mid - 1);
        QuickSort(a, mid + 1, right);

    }
}

void QuickSortNoR(int* a, int left, int right){//typedef int STDatatype
    Stack st;
    StackInit(&st);
    if(left < right){
        StackPush(&st, right);
        StackPush(&st, left);
    }
    while (StackEmpty(&st) == 0){
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);
        //划分当前区间
        int mid = PrevCurPointer(a, begin, end);
        //划分左右子区间
        if(begin < mid - 1){
            StackPush(&st, mid - 1);
            StackPush(&st, begin);
        }
        if(mid + 1 < end){
            StackPush(&st, end);
            StackPush(&st, mid + 1);
        }
    }
}

//时间: N * logN
//空间: N + logN ~ N
//稳定
void _MergeSort(int*a, int left, int right, int* tmp){
    //区间只剩一个元素, 不需要分解和归并
    if(left >= right)
        return;
    //分解
    int mid = left + (right - left) / 2;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    //归并 [left, mid] , [mid + 1, right]
    int begin1 = left, end1 = mid,
            begin2 = mid + 1, end2 = right;  //begin1 ~ end2 --> left ~ right
    int tmpindex = begin1;
    while (begin1 <= end1 && begin2 <= end2){
        // < 不稳定   <= 稳定
        if (a[begin1] <= a[begin2]){
            tmp[tmpindex++] = a[begin1++];
        }else{
            tmp[tmpindex++] = a[begin2++];
        }
    }
    while (begin1 <= end1){
        tmp[tmpindex++] = a[begin1++];
    }
    while (begin2 <= end2){
        tmp[tmpindex++] = a[begin2++];
    }
    //拷贝到原有数组的对应区间
    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* a, int n){
    int* tmp = (int*)malloc(sizeof(int));
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
    tmp = NULL;
}

//计数排序
void CountSort(int* a, int n){
    //范围: min ~ max
    int min = a[0], max = a[0];
    int i;
    //获取数据范围 可有可无 节省空间
    for (i = 1; i < n; ++i){
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int* CountArr = (int*)malloc(sizeof(int) * range);
    memset(CountArr, 0, sizeof(int) * range);
    //计数
    for (i = 0; i < n; ++i) {
        CountArr[a[i] - min]++;
    }
    //排序
    int index = 0;
    for (i = 0; i < n; ++i) {
        while(CountArr[i]--){
            a[index] = i + min;
        }
    }
}

void PrintArray(int* a , int n){
    int i;
    for (i = 0; i < n ; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void testSort(){
    srand(time(NULL));
    int i, num ;
    scanf("%d" ,&num);

    int* arr1 = (int*)malloc(sizeof(int) * num);
    int* arr2 = (int*)malloc(sizeof(int) * num);
    int* arr3 = (int*)malloc(sizeof(int) * num);
    int* arr4 = (int*)malloc(sizeof(int) * num);
    int* arr5 = (int*)malloc(sizeof(int) * num);

    for(i = 0;i < num; ++i){
        arr1[i] = rand();
    }
    memcpy(arr2 , arr1 , sizeof(int)* num);
//    memcpy(arr3 , arr2 , sizeof(int)* num);
//    memcpy(arr4 , arr3 , sizeof(int)* num);

    size_t  begin1 , end1 , begin2 , end2, begin3 , end3, begin4 , end4, begin5, end5;

//    begin1 = clock();
//    InsertSort(arr1 , num);
//    end1 = clock();
//    printf("InertSort : %d \n", end1 - begin1);

    begin2 = clock();
    Shell(arr2 , num);
    end2 = clock();
    printf("ShellSort : %d \n", end2 - begin2);

//    begin3 = clock();
//    SelectSort(arr3 , num);
//    end3 = clock();
//    printf("SelectSort : %d \n", end3 - begin3);

    begin4 = clock();
    HeapSort(arr4 , num);
    end4 = clock();
    printf("QueickSort : %d \n", end4 - begin4);

    begin5 = clock();
    QuickSort(arr5 ,0, num - 1);
    end5 = clock();
    printf("HeapSort : %d \n", end5 - begin5);

}

int main(){
    int a[10] = {5, 10, 1, 6, 3, 7, 22 ,9 ,8 ,4};
    PrintArray(a , sizeof(a)/ sizeof(a[0]));
//    SelectSort(a , sizeof(a)/ sizeof(a[0]));

//    HeapSort(a , sizeof(a)/ sizeof(a[0]));
//    BubbleSort(a , sizeof(a)/ sizeof(a[0]));
//    PrintArray(a , sizeof(a)/ sizeof(a[0]));
//
//    Shell(a , sizeof(a)/ sizeof(a[0]));
//    InsertSort(a , 10);
//    PrintArray(a , sizeof(a)/ sizeof(a[0]));

    testSort();
    return 0;
}
