//
// Created by 28943 on 2019/9/20.
//

#include "List.h"

void ListInit(List* pls){
    assert(pls);
    pls->_head = CreatNode(0);
    pls->_head->_prev = pls->_head;
    pls->_head->_next = pls->_head;

}
void ListDestory(List* pls){
    assert(pls);
    ListNode* cur = pls->_head->_next;
    while(cur != pls->_head){
        ListNode* next = cur->_next;
        free(cur);
        cur = next;
    }
    free(pls->_head);
}
ListNode* CreatNode(DataType x) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->_next = newNode->_prev = NULL;
    newNode->_data = x;
    return newNode;
}

void ListPushBack(List* pls , DataType x){
    assert(pls);
    ListNode* newNode = CreatNode(x);
    ListNode* tail = pls->_head->_prev;

    newNode->_next = pls->_head;
    newNode->_prev = tail;
    tail->_next = newNode;
    tail = tail->_next;
    pls->_head->_prev = tail;

}
void ListPopBack(List* pls){
    assert(pls);
    if(pls->_head == pls->_head->_next)
        return;
    ListNode* tail = pls->_head->_prev;
    ListNode* prev = tail->_prev;
    ListNode* next = tail->_next;
    prev->_next = next;
    next->_prev = prev;
    free(tail);
    tail = NULL;
}
void ListPushFront(List* pls , DataType x){
    assert(pls);
//    ListNode* newNode = CreatNode(x);
//    ListNode* cur = pls->_head->_next;
//    newNode->_next = cur;
//    newNode->_prev = pls->_head;
//    pls->_head->_next = newNode;
//    cur->_prev = newNode;
    ListInser(pls->_head->_next,x);

}
void ListPopFront(List* pls){
//    assert(pls);
//    ListNode* cur = pls->_head->_next;
//    if(pls->_head == pls->_head->_next)
//        return;
//    pls->_head->_next = cur->_next;
//    cur->_next->_prev = pls->_head;
//    free(cur);
//    cur = NULL;
    ListErase(pls->_head->_next);
}

ListNode* ListFind(List* pls,DataType x){
    assert(pls);
    ListNode* cur = pls->_head->_next;
    while(cur != pls->_head){
        if(cur->_data == x){
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}
void ListInser(ListNode* pos,DataType x){
    assert(pos);

    ListNode* cur = pos->_prev;
    ListNode* newNode = CreatNode(x);
    newNode->_prev = pos->_prev;
    newNode->_next = pos;
    cur->_next = newNode;
    pos->_prev = newNode;
}
void ListErase(ListNode* pos){
    //该位置(前)删除
    assert(pos);
    if(pos->_prev == NULL)
        return;
    pos->_prev->_next = pos->_next;
    pos->_next->_prev = pos->_prev;
    free(pos);
    pos = NULL;
}
void ListRemove(List* pls,DataType x){
    assert(pls);
    if(pls->_head == pls->_head->_next)
        return;
    ListNode* cur = pls->_head->_next;
    while(cur != pls->_head){
        if(cur->_data == x){
            ListErase(cur);
            return;
        }
        cur = cur->_next;
    }
}

void ListPrint(List* pls){
    assert(pls);
    ListNode* cur = pls->_head->_next;
    while(cur != pls->_head){
        printf("%d->",cur->_data);
        cur = cur->_next;
    }
    printf("\n");
}

void TestList(){
    List pls;

    ListInit(&pls);

    ListPushBack(&pls,1);
    ListPushBack(&pls,1);
    ListRemove(&pls,1);

    ListPrint(&pls);


    ListPushBack(&pls,2);
    ListPushBack(&pls,3);
    ListPushBack(&pls,4);
    ListPrint(&pls);

    ListPushFront(&pls,-1);
    ListPushFront(&pls,-2);
    ListPrint(&pls);

    ListPopBack(&pls);
    ListPopFront(&pls);
    ListPrint(&pls);

    ListDestory(&pls);
}

int main(){
    TestList();
}

