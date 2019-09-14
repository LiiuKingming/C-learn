#include "SeqList.h"

void TestSeqList(){
    SeqList sl;
    SeqListInit(&sl,10);
    SeqListPrint(&sl);

    SeqListPushBack(&sl,2);
    SeqListPushBack(&sl,1);
    SeqListPushBack(&sl,1);
    SeqListPushBack(&sl,56);
    SeqListPushBack(&sl,1);
    SeqListPrint(&sl);

    SeqListErase(&sl,3);
    SeqListPrint(&sl);

    SeqListModify(&sl,1,10086);
    SeqListPrint(&sl);

    SeqListFind(&sl,1);
    SeqListFind(&sl,10);

    SeqListPushFront(&sl,6);
    SeqListPrint(&sl);
    SeqListPopFront(&sl);
    SeqListPrint(&sl);

    SeqListPushBack(&sl,1);
    SeqListPushBack(&sl,2);
    SeqListPushBack(&sl,3);
    SeqListPushBack(&sl,1);
    SeqListPrint(&sl);

    SeqListPopFront(&sl);
    SeqListPrint(&sl);

    SeqListPopBack(&sl);
    SeqListPrint(&sl);

    SeqListPushFront(&sl,7);
    SeqListPrint(&sl);

    SeqListInsert(&sl,0,99);
    SeqListPrint(&sl);

    SeqListRemove(&sl,1);
    SeqListPrint(&sl);

    SeqListBubbleSort(&sl);
    SeqListPrint(&sl);

    SeqListBinaryFind(&sl,5);

    printf("a\n");
    SeqListRemoveAll(&sl,1);
    SeqListPrint(&sl);

    SeqListDestory(&sl);
}

int main(){
    TestSeqList();
    return 0;
}