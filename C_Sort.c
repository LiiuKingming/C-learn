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
    //??????: ????????????, ??��?????????O(N)
    //         ????????????????? , ??��???O(N)
    assert(a);
    int i;
    for(i = 0;i < n-1 ;++i){
        //????????????
        //??????????????????????��??
        int end = i;
        //??end + 1???��??????????????��??
        int tmp = a[end + 1];
        while(end >= 0 && a[end] > tmp){
            a[end + 1 ] = a[end];
            --end;
        }
        //????????��??
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
        //??????????????��????, ????????��??
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
        //?��?��??????????
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
    // 0~(n - 2) / 2 ???��??????????
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
            //????????��?????��??
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
            //?????��??????????????????
            flag = 1;
            if(a[cur] < a[cur - 1]){
                Swap(&a[cur] , &a[cur - 1]);
            }
        }
        if(flag == 0)
            break;
    }
}

//����ȡ�з�
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

    //���һ��С��key��λ��
    int prev = left;
    //��һ��С��key��λ��
    int cur = left + 1;
    int key = a[left];
    while (cur <= right){
        //�����һ��С��key��λ������һ��С��key��λ�ò�����
        //˵���м��д���key��ֵ, ���н���, ��-->����ƶ�, С<--��ǰ�ƶ�
        if(a[cur]< key && ++prev != cur){//������
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
        //���ұ���С
        while (left > right && a[right] >= key){
            --right;
        }
        a[left] = a[right];
        //������Ҵ��
        while (left < right && a[right] <= key)
            ++left;
        //���
        a[right] = a[left];
    }
    //���key
    a[left] = key;
    return left;
}

//���ŵ�һ������:ȷ����׼ֵ��λ��
int PartSort(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    int key = a[left];
    int start = left;
    //Ѱ�Ҵ�СԪ�ؽ���
    while(left < right){
        //�ȴ��ұ���С��key��ֵ
        while(left < right && a[right] >= key)
            --right;
        //������Ҵ���key��ֵ
        while(left < right && a[left] <= key)
            ++left;
        Swap(&a[left], &a[right]);
    }
    //key��λ��ȷ�� : left right ������λ��
    Swap(&a[start], &a[left]);
    return left;
}
//�ռ�: �ռ���Ը��� ���ĵݹ������--> logN
//ʱ��: N * logN
//�������� ʱ��Ч�����--> N^2
void QuickSort(int* a, int left, int right){
    if(left >= right)
        return;
        //С�����Ż�: С���䲻�ٵ��õݹ�
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
        //���ֵ�ǰ����
        int mid = PrevCurPointer(a, begin, end);
        //��������������
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

//ʱ��: N * logN
//�ռ�: N + logN ~ N
//�ȶ�
void _MergeSort(int*a, int left, int right, int* tmp){
    //����ֻʣһ��Ԫ��, ����Ҫ�ֽ�͹鲢
    if(left >= right)
        return;
    //�ֽ�
    int mid = left + (right - left) / 2;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    //�鲢 [left, mid] , [mid + 1, right]
    int begin1 = left, end1 = mid,
            begin2 = mid + 1, end2 = right;  //begin1 ~ end2 --> left ~ right
    int tmpindex = begin1;
    while (begin1 <= end1 && begin2 <= end2){
        // < ���ȶ�   <= �ȶ�
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
    //������ԭ������Ķ�Ӧ����
    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* a, int n){
    int* tmp = (int*)malloc(sizeof(int));
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
    tmp = NULL;
}

//��������
void CountSort(int* a, int n){
    //��Χ: min ~ max
    int min = a[0], max = a[0];
    int i;
    //��ȡ���ݷ�Χ ���п��� ��ʡ�ռ�
    for (i = 1; i < n; ++i){
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int* CountArr = (int*)malloc(sizeof(int) * range);
    memset(CountArr, 0, sizeof(int) * range);
    //����
    for (i = 0; i < n; ++i) {
        CountArr[a[i] - min]++;
    }
    //����
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
