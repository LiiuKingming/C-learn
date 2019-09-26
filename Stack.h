//
// Created by 28943 on 2019/9/21.
//

#ifndef C_HOMEWORK_STACK_H
#define C_HOMEWORK_STACK_H

#endif //C_HOMEWORK_STACK_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define STACK_INIT_SIZE 10

typedef int Datatype;

typedef struct Stack{
    Datatype* _a; //数组指针
    size_t _top;
    size_t _capacity;
}Stack;

void StackInit(Stack* st);
void StackDestory(Stack* st);

void StackPush(Stack* st,Datatype x);
void StackPop(Stack* st);
Datatype StackTop(Stack* st);
int StackEmpty(Stack* st);
size_t StackSize(Stack* st);
void StackPrint(Stack* st);

void Test();