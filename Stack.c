//
// Created by 28943 on 2019/9/21.
//

#include "Stack.h"

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
    free(st->_a);
    st->_a = NULL;
//    free(ps->_base);
//    ps->_base = NULL;
//    ps->_top = NULL;
//    ps->_capacity = 0;
}

void StackPush(Stack* st,Datatype x){
    //尾插
    //检查容量
    assert(st);
    if(st->_top == st->_capacity) {
        size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
        st->_a = (Datatype *) realloc(st->_a, newC * sizeof(Datatype));
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
Datatype StackTop(Stack* st){
    assert(st);
    return st->_a[st->_top - 1];
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
void StackPrint(Stack* st){
    assert(st);
    while(StackEmpty(st) != 1){
        printf("%d ",StackTop(st));
        StackPop(st);
    }
    printf("\n");
}

void Test(){
    Stack st;
    StackInit(&st);

    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,4);
    StackPush(&st,3);

    StackPop(&st);

    StackPrint(&st);

}

int main(){
    Test();
}