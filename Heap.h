//
// Created by 28943 on 2019/9/24.
//

#ifndef C_HOMEWORK_HEAP_H
#define C_HOMEWORK_HEAP_H

#endif //C_HOMEWORK_HEAP_H

typedef int HPDataType;
typedef struct Heap{
    HPDataType* _a;
    int _size;
    int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapInit2(Heap* hp);

void ShiftDown(HPDataType* a,int n,int root);

void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// 堆排序
void HeapSort(int* a, int n);
void TestHeap();