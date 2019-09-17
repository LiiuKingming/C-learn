//
// Created by 28943 on 2019/9/24.
//

#ifndef C_HOMEWORK_QUEUE_H
#define C_HOMEWORK_QUEUE_H

#endif //C_HOMEWORK_QUEUE_H

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
void QueuePrint(Queue* q);

void Test();


