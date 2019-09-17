//
// Created by 28943 on 2019/9/24.
//

#include "Queue.h"

void QueueInit(Queue* q){
    assert(q);
    q->_front = q->_rear = NULL;
}
void QueueDestory(Queue* q);

QueueNode* BuyQueueNode(DataType x){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->_next = NULL;
    newNode->_data = x;
    return newNode;
}
void QueuePush(Queue* q ,DataType x){
    assert(q);
    QueueNode* newNode = BuyQueueNode(x);
    if(q->_front == NULL)
        q->_front = newNode;
    q->_rear->_next = newNode;
    q->_rear = newNode;

}
void QueuePop(Queue* q){
    assert(q);

}
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueEmpty(Queue* q);
int QueueSize(Queue* q);
void QueuePrint(Queue* q);

void Test(){
    Queue q;
}

int main(){
    Test();
    return 0;
}