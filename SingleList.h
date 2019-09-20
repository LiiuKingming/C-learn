//
// Created by 28943 on 2019/9/15.
//

#ifndef C_HOMEWORK_SINGLELIST_H
#define C_HOMEWORK_SINGLELIST_H

#endif //C_HOMEWORK_SINGLELIST_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;
typedef struct SListNode{//节点
    DataType _data;
    struct SListNode* _next;
}SListNode;

typedef struct SList{//单链表
    SListNode* _head;//头结点
}SList;

void SListInit(SList* sl);//初始化
void SListDestory(SList* sl);//摧毁释放内存

SListNode* CreatNode(DataType x);//创建一个空间
void SListPushBack(SList* sl,DataType x);//尾插
void SListPopBack(SList* sl);//尾删
void SListPushFront(SList* sl,DataType x);//头插
void SListPopFront(SList* sl);//头删
SListNode* SListFind(SList* sl,DataType x);

void SListInsertAfter(SListNode* pos,DataType x);//在pos后插入
void SlistEraseAfter(SListNode* pos);
void SListRemoveAll(SList* sl,DataType x);

void SListPrint(SList* sl);
void TestSList();
