#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;

typedef struct QueueNode{
    struct QueueNode* _next;
    DataType _data;
}QueueNode;

typedef struct Queue{
    QueueNode* _front;
    QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);

QueueNode* BuyQueueNode(DataType x);
void QueuePush(Queue* q ,DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueEmpty(Queue* q);
int QueueSize(Queue* q);

void QueueInit(Queue* q){
    assert(q);
    q->_front = q->_rear = NULL;
}
void QueueDestory(Queue* q){
    assert(q);
    while(q->_front){
        q->_rear = q->_front->_next;
        free(q->_front);
        q->_front = q->_rear;
    }
}

QueueNode* BuyQueueNode(DataType x){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->_next = NULL;
    newNode->_data = x;
    return newNode;
}
void QueuePush(Queue* q ,DataType x){
    assert(q);
    QueueNode* newNode = BuyQueueNode(x);
    if(q->_front == NULL) {//ͷԪ��
        q->_front = newNode;
        q->_rear = newNode;
    }else{
        q->_rear->_next = newNode;
        q->_rear = q->_rear->_next;
    }
}
void QueuePop(Queue* q){
    assert(q);
    if(q->_front){
        QueueNode* next = q->_front->_next;
        //ɾ��������
        free(q->_front);
        q->_front = next;
        //ɾ����Ϊ���һ��Ԫ��
        if(q->_front == NULL)
            q->_rear = NULL;
    }
//    if(q == NULL)
//        return;
//    QueueNode* cur = q->_front;
//    q->_front = q->_front->_next;
//    free(cur);
//    cur = NULL;
}
DataType QueueFront(Queue* q){
    assert(q);
    if(q->_front)
        return q->_front->_data;
    return -1;
}
DataType QueueBack(Queue* q){
    assert(q);
    return q->_rear->_data;
}
int QueueEmpty(Queue* q){
    assert(q);
    if(q->_front != NULL)
        return 0;
    else
        return 1;
}
int QueueSize(Queue* q){
    assert(q);
    DataType count = 0;
    QueueNode* cur = q->_front;
    while(cur){
        ++count;
        cur = cur->_next;
    }
    printf("��������%d��Ԫ��\n",count);
    return count;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {//�ڶ��ϴ����ṹ
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    assert(obj);
    //�ж϶����Ƿ�Ϊ��
    //Ԫ�ش���ǿն��еĶ�β
    
    if(QueueEmpty(&obj->q1) == 0){//q1��Ϊ��
        QueuePush(&obj->q1 , x);
    }else{
        QueuePush(&obj->q2 , x);
    }

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    //�ǿն��е�Ԫ���ƶ����ն���
    assert(obj);
    Queue* emptyQ , *fullQ;
    emptyQ = &obj->q2;
    fullQ = &obj->q1;
    int front;
    if(QueueEmpty(&obj->q2) == 0){//q2�ǿս���
        emptyQ = &obj->q1;
        fullQ = &obj->q2;
    }

    while(QueueSize(fullQ) > 1){
         QueuePush(emptyQ , QueueFront(fullQ));
        QueuePop(fullQ);
    }
    front = QueueFront(fullQ);
    QueuePop(fullQ);

    return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
     assert(obj);
    Queue* emptyQ , *fullQ;
    emptyQ = &obj->q2;
    fullQ = &obj->q1;
    int front;
    if(QueueEmpty(&obj->q2) == 0){//q2�ǿս���
        emptyQ = &obj->q1;
        fullQ = &obj->q2;
    }

    while(QueueSize(fullQ) > 1){
         QueuePush(emptyQ , QueueFront(fullQ));
        QueuePop(fullQ);
    }
    front = QueueFront(fullQ);
    
    QueuePush(emptyQ , QueueFront(fullQ));
    QueuePop(fullQ);

    return front;
}


/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/