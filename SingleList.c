//
// Created by 28943 on 2019/9/15.
//

#include "SingleList.h"

void SListInit(SList* sl){
    assert(sl);
    sl->_head = NULL;
}

void SListDestory(SList* sl){
    assert(sl);
    SListNode* cur = sl->_head;
    while (cur){
        SListNode* next = cur->_next;//next保存cur的next
        free(cur);//释放cur当前位置申请的内存
        cur = next;//cur当前位置更新为next
    }
    sl->_head = NULL;
    printf("成功销毁!");
}

SListNode* CreatNode(DataType x){
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    newNode->_data = x;
    newNode->_next = NULL;
    return newNode;
}

void SListPushBack(SList* sl,DataType x){//尾插
    assert(sl);
    if(sl->_head == NULL){
        sl->_head = CreatNode(x);
    } else{//找到最后一个节点
        SListNode* cur = sl->_head;
        while(cur->_next){
            cur = cur->_next;
        }
        cur->_next = CreatNode(x);
    }
    printf("newNode插入成功!\n");
}

void SListPopBack(SList* sl){//尾删
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* prev = NULL;
    if(cur == NULL){
        printf("删除失败!表中无数据!\n");
        return;
    }
    while (cur->_next){
        prev = cur;
        cur = cur->_next;
    }
    free(cur);
    cur= NULL;
    if(prev == NULL) {//删除的为头结点
        sl->_head = NULL;
    }else{
        prev->_next = NULL;
    }
    printf("删除成功!\n");
}

void SListPushFront(SList* sl,DataType x){//头插
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* newNode = CreatNode(x);
    newNode->_next = cur;
    sl->_head = newNode;
    printf("newNode链接成功!\n");
}

void SListPopFront(SList* sl){//头删
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* next = cur->_next;
    if(sl->_head == NULL){
        return;
    }
    free(cur);
    cur = NULL;
    sl->_head = next;
    //新head的next本来就是ok的,只要将head连接到next上就行
    printf("删除成功!\n");
}

SListNode* SListFind(SList* sl,DataType x){
    assert(sl);

    SListNode* cur = sl->_head;
    /*
    while(cur->_data != x){
        cur = cur->_next;
    }
    return cur;
    */
    int count = 0;
    while (cur){
        while(cur->_data == x){
            printf("找到了%d位于第%d位\n",x,count);
            break;
        }
        cur = cur->_next;
        ++count;
    }

    return cur;//返回第二个x
}

void SListInsertAfter(SListNode* pos,DataType x){
    assert(pos);
    SListNode* newNode = CreatNode(x);
    SListNode* cur = pos->_next;
    pos->_next = newNode;
    newNode->_next = cur;
    printf("posAfter添加成功!\n");
}

void SlistEraseAfter(SListNode* pos){
    assert(pos);
    SListNode* cur = pos->_next;
    if(pos->_next == NULL){
        printf("无需删除!\n");
        return;
    }
    SListNode* next = cur->_next;
    pos->_next = next;
    free(cur);
    cur = NULL;
    printf("pos删除成功!\n");
}

void SListRemoveAll(SList* sl,DataType x){
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* prev = NULL;
    while (cur){
        if(cur->_data == x ){
            if(prev == NULL){
                sl->_head = cur->_next;
                free(cur);
                cur = sl->_head;
                printf("remove 1删除成功!\n");
            }else{
                prev->_next = cur->_next;
                free(cur);
                cur = prev->_next;
                printf("remove 2删除成功!\n");
            }
        }else{
            prev = cur;
            cur = cur->_next;
        }
    }
}

void SListPrint(SList* sl){
    assert(sl);
    SListNode* cur = sl->_head;
    while(cur){
        printf("%d->",cur->_data);
        cur = cur->_next;
    }
    printf("\n");
}



void TestSList(){
    SList sl;
    SListInit(&sl);
    SListPushBack(&sl,2);
    SListPushBack(&sl,2);
    SListRemoveAll(&sl,2);
    SListPrint(&sl);
/*
    SListPushFront(&sl,1);
    SListPrint(&sl);
    printf("\n");

    SListPushBack(&sl,2);
    SListPushBack(&sl,3);
    SListPushBack(&sl,4);
    SListPushBack(&sl,2);
    SListPushBack(&sl,5);
    SListPrint(&sl);
    printf("\n");

    SListRemoveAll(&sl,2);
    SListPrint(&sl);
    printf("\n");

    SListFind(&sl,2);

    SlistEraseAfter(sl._head);
    SListPrint(&sl);
    printf("\n");

    SListPopBack(&sl);
    SListPrint(&sl);
    printf("\n");

    SListInsertAfter(sl._head->_next,3);
    SListPrint(&sl);
    printf("\n");

    SListPopFront(&sl);
    SListPrint(&sl);
    printf("\n");
*/

    SListDestory(&sl);
}

int main(){
    TestSList();
}