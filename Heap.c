//
// Created by 28943 on 2019/9/24.
//

#include "Heap.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void HeapInit(Heap* hp, HPDataType* a, int n){
    assert(hp && a);
    int i;
    hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    for(i = 0 ; i < n;++i){
        hp->_a[i] = a[i];
    }
    //调整 从最后一棵子树开始调整
    for (i = (n - 2) / 2; i >= 0; --i) {
        ShiftDown(hp->_a , n , i);
    }
    hp->_size = hp->_capacity = n;

}

void HeapInit2(Heap* hp){

}

void Swap(HPDataType* pa,HPDataType* ch){
    int tmp = *pa;
    *pa = *ch;
    *ch = tmp;
}
//向下调整,调成大根堆
void ShiftDown(HPDataType* a,int n,int root){//数组个数n
    //(n - 2) / 2是最后一个非叶子索引
    // 0~(n - 2) / 2 所有非叶子节点索引
    assert(a);
    int parent = root;
    int child = 2 * parent + 1;
    //当前节点是否有child
    while (child < n){
        //是否有右child,如果有,两者当中选最大
        if(child + 1 < n && a[child + 1] > a[child])
            ++child;
        //child是否大于parent
        if(a[child] > a[parent]){
            //交换
            Swap(&a[child] , &a[parent]);
            //更新下一次调整的位置
            parent = child;
            child = 2 * parent + 1;
        }else{
            //以parent为根的子树已经是一个大堆,结束调整
            break;
        }
    }
}

void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// 堆排序
void HeapSort(int* a, int n);

void HeapPrint(Heap* hp){
    assert(hp);
    for (int i = 0; i < hp->_size ; ++i) {
        printf("%d ",hp->_a[i]);
    }
    printf("\n");
}
void TestHeap(){
    int a[]={1,5,3,8,7,6};
    //建大堆 调完 876513
    Heap hp;

    HeapInit(&hp,a, sizeof(a) / sizeof(a[0]));
    HeapPrint(&hp);

}

int main(){
    TestHeap();
    return 0;
}