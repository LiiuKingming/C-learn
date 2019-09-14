//
// Created by 28943 on 2019/9/4.
//

#ifndef C_HOMEWORK_SEQLIST_H
#define C_HOMEWORK_SEQLIST_H

#endif //C_HOMEWORK_SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define INCREASE_SIZE 10

typedef int DataType;

typedef struct SeqList{
    DataType* _array;
    size_t _size;//实际存放元素个数
    size_t _capacity;//开辟空间大小
}SeqList;

void SeqListInit(SeqList* sl,size_t capacity);//初始化
void SeqListDestory(SeqList* sl);//删除

void CheckCapacity(SeqList* sl);
void SeqListPushBack(SeqList* sl,DataType x);//尾插
void SeqListPopBack(SeqList* sl);//尾删
void SeqListPushFront(SeqList* sl,DataType x);//头插
void SeqListPopFront(SeqList* sl);//头删

void  SeqListFind(SeqList* sl,DataType x);//查找
void SeqListInsert(SeqList* sl,size_t pos,DataType x);//指定位置插入
void SeqListErase(SeqList* sl,size_t pos);//指定位置删除
void SeqListRemove(SeqList* sl,DataType x);//删除指定元素
void SeqListModify(SeqList* sl,size_t pos,DataType x);//修改指定元素值
void SeqListPrint(SeqList* sl);//打印接口

void SeqListBubbleSort(SeqList* sl);

int SeqListBinaryFind(SeqList* sl,DataType x);

void SeqListRemoveAll(SeqList* sl,DataType x);//删除所有指定元素







