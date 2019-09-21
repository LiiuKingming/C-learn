//
// Created by 28943 on 2019/9/20.
//

#ifndef C_HOMEWORK_LIST_H
#define C_HOMEWORK_LIST_H

#endif //C_HOMEWORK_LIST_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct ListNode{
    DataType _data;
    struct ListNode* _prev;
    struct ListNode* _next;
}ListNode;

typedef struct List{
    ListNode* _head;
}List;

ListNode* CreatNode(DataType x);
void ListInit(List* pls);
void ListDestory(List* pls);

void ListPushBack(List* pls , DataType x);
void ListPopBack(List* pls);
void ListPushFront(List* pls , DataType x);
void ListPopFront(List* pls);

ListNode* ListFind(List* pls,DataType x);
void ListInser(ListNode* pos,DataType x);
void ListErase(ListNode* pos);//该位置(前)删除
void ListRemove(List* pls,DataType x);

void ListPrint(List* pls);

void TestList();
