typedef int Datatype;

typedef struct Stack{
    Datatype* _a; //����ָ��
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

void StackInit(Stack* st){
    assert(st);
    st->_a = NULL;
    st->_capacity = st->_top = 0;
    //��ջ
}
void StackDestory(Stack* st){
    assert(st);
    free(st->_a);
    st->_a = NULL;
}

void StackPush(Stack* st,Datatype x){
    //β��
    //�������
    assert(st);
    if(st->_top == st->_capacity) {
        size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
        st->_a = (Datatype *) realloc(st->_a, newC * sizeof(Datatype));
        st->_capacity = newC;
    }
    st->_a[st->_top++] = x;
}

void StackPop(Stack* st){
    //βɾ
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
    return st->_top;
}

bool isValid(char* s){
    Stack st;
    static char str[][2] = {
        {'(',')'},
        {'[',']'},
        {'{','}'}
    };
    StackInit(&st);
    while(*s){
        //�����ջ
        int i;
        for(i = 0 ; i < 3; ++i){
            if(*s == str[i][0]){//��ǰ�ַ��Ƿ����ĳ������ַ�
                //����ַ���ջ
                StackPush(&st,*s);
                ++s;
                break;
            }
        }
        //��ǰ���������ұ��ַ�
        if(i == 3){//�ж��Ƿ�Ϊ�ұ�����
            //�ж��ַ��Ƿ��ջ���ַ�ƥ��
            char top;
            if(StackEmpty(&st) == 0)
                top = StackTop(&st);
            else{
                
                return false;
            }
             //�жϸ���һ���ұ��ַ�ƥ��
            for( i = 0 ; i < 3 ; ++i ){
                if(*s == str[i][1]){
                    if(top == str[i][0]){
                        StackPop(&st);
                        ++s;
                        break;
                    }else{
                        
                        return false;
                    }    
                }  
            }
        }    
    }  
    if(StackEmpty(&st))
        return true;
    else{
        
        return false;
    }     
}