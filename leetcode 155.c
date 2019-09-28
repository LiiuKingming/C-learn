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

void StackInit(Stack* st){
    assert(st);
    st->_a = NULL;
    st->_capacity = st->_top = 0;
    //空栈

}
void StackDestory(Stack* st){
    assert(st);
    free(st->_a);
    st->_a = NULL;
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
    return st->_a[st->_top - 1];//要不要 - 1?
}
int StackEmpty(Stack* st){
    assert(st);
    return st->_top == 0 ? 1 : 0 ;
}
size_t StackSize(Stack* st){
    assert(st);
    return st->_top;
}

typedef struct {
    Stack S;
    Stack minS;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
   MinStack* st = (MinStack*)malloc(sizeof(MinStack));
   StackInit(&st->S);
   StackInit(&st->minS);
   return st;
}

void minStackPush(MinStack* obj, int x) {
    StackPush(&obj->S , x);
    if(StackEmpty(&obj->minS) == 1){//空
        StackPush(&obj->minS , x);
    }else{
        if(StackTop(&obj->minS) >= x){
            StackPush(&obj->minS , x);
        }
    }
}
    

void minStackPop(MinStack* obj) {
    if(StackTop(&obj->S) == StackTop(&obj->minS)){
        StackPop(&obj->S);
        StackPop(&obj->minS);
    }else{
        StackPop(&obj->S);
    }
}

int minStackTop(MinStack* obj) {
    return StackTop(&obj->S);
}
int minStackGetMin(MinStack* obj) {
    return StackTop(&obj->minS);
}

void minStackFree(MinStack* obj) {
    StackDestory(&obj->S);
    StackDestory(&obj->minS);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/