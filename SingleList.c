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
        SListNode* next = cur->_next;//next����cur��next
        free(cur);//�ͷ�cur��ǰλ��������ڴ�
        cur = next;//cur��ǰλ�ø���Ϊnext
    }
    sl->_head = NULL;
    printf("�ɹ�����!");
}

SListNode* CreatNode(DataType x){
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    newNode->_data = x;
    newNode->_next = NULL;
    return newNode;
}

void SListPushBack(SList* sl,DataType x){//β��
    assert(sl);
    if(sl->_head == NULL){
        sl->_head = CreatNode(x);
    } else{//�ҵ����һ���ڵ�
        SListNode* cur = sl->_head;
        while(cur->_next){
            cur = cur->_next;
        }
        cur->_next = CreatNode(x);
    }
    printf("newNode����ɹ�!\n");
}

void SListPopBack(SList* sl){//βɾ
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* prev = NULL;
    if(cur == NULL){
        printf("ɾ��ʧ��!����������!\n");
        return;
    }
    while (cur->_next){
        prev = cur;
        cur = cur->_next;
    }
    free(cur);
    cur= NULL;
    if(prev == NULL) {//ɾ����Ϊͷ���
        sl->_head = NULL;
    }else{
        prev->_next = NULL;
    }
    printf("ɾ���ɹ�!\n");
}

void SListPushFront(SList* sl,DataType x){//ͷ��
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* newNode = CreatNode(x);
    newNode->_next = cur;
    sl->_head = newNode;
    printf("newNode���ӳɹ�!\n");
}

void SListPopFront(SList* sl){//ͷɾ
    assert(sl);
    SListNode* cur = sl->_head;
    SListNode* next = cur->_next;
    if(sl->_head == NULL){
        return;
    }
    free(cur);
    cur = NULL;
    sl->_head = next;
    //��head��next��������ok��,ֻҪ��head���ӵ�next�Ͼ���
    printf("ɾ���ɹ�!\n");
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
            printf("�ҵ���%dλ�ڵ�%dλ\n",x,count);
            break;
        }
        cur = cur->_next;
        ++count;
    }

    return cur;//���صڶ���x
}

void SListInsertAfter(SListNode* pos,DataType x){
    assert(pos);
    SListNode* newNode = CreatNode(x);
    SListNode* cur = pos->_next;
    pos->_next = newNode;
    newNode->_next = cur;
    printf("posAfter��ӳɹ�!\n");
}

void SlistEraseAfter(SListNode* pos){
    assert(pos);
    SListNode* cur = pos->_next;
    if(pos->_next == NULL){
        printf("����ɾ��!\n");
        return;
    }
    SListNode* next = cur->_next;
    pos->_next = next;
    free(cur);
    cur = NULL;
    printf("posɾ���ɹ�!\n");
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
                printf("remove 1ɾ���ɹ�!\n");
            }else{
                prev->_next = cur->_next;
                free(cur);
                cur = prev->_next;
                printf("remove 2ɾ���ɹ�!\n");
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