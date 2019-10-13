#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int STDatatype;

typedef struct Stack{
    STDatatype* _a; //数组指针
    size_t _top;
    size_t _capacity;
}Stack;

void StackInit(Stack* st);
void StackDestory(Stack* st);

void StackPush(Stack* st, STDatatype x);
void StackPop(Stack* st);

STDatatype StackTop(Stack* st);
int StackEmpty(Stack* st);
size_t StackSize(Stack* st);

void StackInit(Stack* st){
    assert(st);
    st->_a = NULL;
    st->_capacity = st->_top = 0;
    //空栈

//    ps->_base = (Datatype*) sizeof(Datatype);
//    ps->_top = NULL;
//    ps->_capacity = STACK_INIT_SIZE;
}
void StackDestory(Stack* st){
    assert(st);
    //st->_top = st->_capacity = 0;
    free(st->_a);
    st->_a = NULL;
//    free(ps->_base);
//    ps->_base = NULL;
//    ps->_top = NULL;
//    ps->_capacity = 0;
}

void StackPush(Stack* st,STDatatype x){
    //尾插
    //检查容量
    assert(st);
    if(st->_top == st->_capacity) {
        size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
        st->_a = (STDatatype *) realloc(st->_a, newC * sizeof(STDatatype));
        st->_capacity = newC;
    }
    st->_a[st->_top++] = x;
}
void StackPop(Stack* st){
    //尾删
    assert(st);
    if(st->_top > 0)
        --st->_top;
}

STDatatype StackTop(Stack* st){//STDatatype
    assert(st);
    return st->_a[st->_top - 1];//要不要 - 1?
}
int StackEmpty(Stack* st){
    assert(st);
    return st->_top == 0 ? 1 : 0 ;
}
size_t StackSize(Stack* st){
    assert(st);
    return st->_top;
//    return ps->_top - ps->_base;
}

typedef struct {
    Stack pushSt;
    Stack popSt;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&mq->pushSt);
    StackInit(&mq->popSt);
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushSt, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int top;
    if(StackEmpty(&obj->popSt)){
        while(StackEmpty(&obj->pushSt) == 0){
            StackPush(&obj->popSt, StackTop(&obj->pushSt));
            StackPop(&obj->pushSt);
        }
    }
    top = StackTop(&obj->popSt);
    StackPop(&obj->popSt);
    return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int top;
    if(StackEmpty(&obj->popSt)){
        while(StackEmpty(&obj->pushSt) == 0){
            StackPush(&obj->popSt, StackTop(&obj->pushSt));
            StackPop(&obj->pushSt);
        }
    }
    top = StackTop(&obj->popSt);
    //StackPop(&obj->popSt);
    return top;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->pushSt) && StackEmpty(&obj->popSt);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->pushSt);
    StackDestory(&obj->popSt);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/