//
// Created by 28943 on 2019/9/4.
//
#include "SeqList.h"

void SeqListInit(SeqList* sl,size_t capacity){//��ʼ��
    assert(sl);
    if(capacity == 0){
        sl->_array = NULL;
        sl->_size = 0;
        sl->_capacity = 0;
    }else{
        sl->_capacity = capacity;
        sl->_size = 0;
        sl->_array = (DataType*)malloc(sizeof(DataType) * sl->_capacity);
        assert(sl);
    }
}
void SeqListDestory(SeqList* sl){//�ݻ��ͷ��ڴ�
    assert(sl);
    free(sl->_array);
    sl->_array = NULL;
    sl->_capacity = 0;
    sl->_size = 0;
    printf("�ɹ�����!\n");
}

void CheckCapacity(SeqList* sl){//�������������
    assert(sl);
    if(sl->_size == sl->_capacity){
        sl->_capacity += INCREASE_SIZE;//��������
        sl->_array = (DataType*)realloc(sl->_array,sizeof(DataType) * sl->_capacity);
    }
}

void SeqListPushBack(SeqList* sl,DataType x){//β��
    assert(sl);
    CheckCapacity(sl);
    /*
    sl->_array[sl->_size] = x;
    ++sl->_size;
    printf("%d��ӳɹ�!\n",x);
     */
    SeqListInsert(sl, sl->_size, x);
}

void SeqListPopBack(SeqList* sl){//βɾ
    assert(sl);
    CheckCapacity(sl);
    /*
    if(sl->_size == 0){
        printf("ɾ��ʧ��,˳�����û��Ԫ��!\n");
        return;
    }
    --sl->_size;
    printf("ɾ��ĩλԪ�سɹ�!\n");
     */
    SeqListErase(sl,sl->_size);
}

void SeqListPushFront(SeqList* sl,DataType x){//ͷ��
    assert(sl);
    CheckCapacity(sl);
/*
    if(sl->_size == 1){
        sl->_array[sl->_size - 1] = x;
    }else{
        for (size_t i = sl->_size ; i >= 1; --i) {
            sl->_array[i] = sl->_array[i - 1];
        }
        sl->_array[0] = x;
    }
    ++sl->_size;
    printf("%d������Ԫ��λ�óɹ�!\n",x);
 */
    SeqListInsert(sl,0,x);

}

void SeqListPopFront(SeqList* sl){//ͷɾ
    assert(sl);
    CheckCapacity(sl);
    /*
    if(sl->_size == 1){
        --sl->_size;
        printf("��Ԫ��ɾ���ɹ�!\n");
    }else{
        for (size_t i = 0; i < sl->_size - 1; ++i) {
            sl->_array[i] = sl->_array[i + 1];
        }
        --sl->_size;
        printf("��Ԫ��ɾ���ɹ�!\n");
    }
     */
    SeqListErase(sl,0);
}

void SeqListFind(SeqList* sl,DataType x) {//����ָ��Ԫ��
    assert(sl);
    if (sl->_size == 0) {
        printf("����ʧ��,˳�����û��Ԫ��!\n");
    }

    int count = 0;
    for (size_t i = 0; i < sl->_size; ++i) {
        if (x == sl->_array[i]) {
            ++count;
            if (count > 1) {
                printf("�Լ���%dλ��\n", i);
                continue;
            }
            printf("%dλ�ڵ�%dλ��\n", x, i);
        }
    }
    if (count == 0) {
        printf("����ʧ��,˳�����û�и�Ԫ��!\n");
    }
}

void SeqListInsert(SeqList* sl,size_t pos,DataType x){//ָ��λ�ò���Ԫ��
    assert(sl);
    if(pos < 0||pos > sl->_size){
        printf("����ʧ��,�����˴����λ��!\n");
        return;
    }
    if(pos == 0){
        sl->_array[pos] = x;
    }else{
        for (size_t i = sl->_size ; i >= pos ; --i) {
            sl->_array[i] = sl->_array[i - 1];
        }
    }

    sl->_array[pos] = x;
    ++sl->_size;
    if (pos == sl->_size) {
        printf("�ɹ������ĩβԪ��!\n");
    } else if (pos == 0) {
        printf("�ɹ���������Ԫ��!\n");
    } else {
        printf("�ɹ����ӵ�%d��Ԫ��!\n", pos);
    }
    /*
    if(pos == 0){//ֱ�ӵ���ͷ��
        SeqListPushFront(sl,x);
    }else if(pos == sl->_size){//ֱ�ӵ���β��
        SeqListPushBack(sl,x);
    }else{
    } */
}

void SeqListErase(SeqList* sl,size_t pos) {//ɾ��ָ��λ��Ԫ��
    assert(sl);
    if (sl->_size == 0) {
        printf("ɾ��ʧ��,˳�����û��Ԫ��!\n");
    }
    if(pos < 0||pos > sl->_size){
        printf("ɾ��ʧ��,�����˴����λ��!\n");
        return;
    }
    for (size_t i = pos; i < sl->_size - 1; ++i) {
        sl->_array[i] = sl->_array[i + 1];
    }
    --sl->_size;
    if (pos == sl->_size) {
        printf("�ɹ�ɾ��ĩβԪ��!\n");
    } else if (pos == 0) {
        printf("�ɹ�ɾ����Ԫ��!\n");
    } else {
        printf("�ɹ�ɾ����%d��Ԫ��!\n", pos);
    }
}

void SeqListRemove(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("ɾ��ʧ��,˳�����û��Ԫ��!\n");
    }
    int count = 0;
    for(size_t i = 0;i < sl->_size ; ++i){
        if(x == sl->_array[i]){
            ++count;
            SeqListErase(sl,i);
            break;
        }
    }
    if(count == 0){
        printf("ɾ��ʧ��,δ�ҵ�ָ����Ԫ��!\n");
    }
}

void SeqListModify(SeqList* sl,size_t pos,DataType x){
    assert(sl);
    if (sl->_size == 0) {
        printf("�޸�ʧ��,˳�����û��Ԫ��!\n");
    }
    if(pos < 0||pos > sl->_size){
        printf("�޸�ʧ��,�����˴����λ��!\n");
        return;
    }
    int tmp = sl->_array[pos];
    sl->_array[pos] = x;
    printf("�ɹ�����%d��Ԫ��%d�޸�Ϊ%d\n",pos,tmp,sl->_array[pos]);
}

void SeqListPrint(SeqList* sl){
    assert(sl);
    if(sl->_size == 0){
        printf("˳�������Ԫ��!\n");
        return;
    }
    for (size_t i = 0; i <= sl->_size - 1 ; ++i) {
        if(i < sl->_size - 1){
            printf("%d,",sl->_array[i]);
            continue;
        }
        printf("%d\n",sl->_array[i]);
        return;
    }
}

void SeqListBubbleSort(SeqList* sl){//����ð������
    assert(sl);
    if(sl->_size == 0){
        printf("˳�������Ԫ��!\n");
        return;
    }
    size_t end = sl->_size ;
    while (end--) {
        for (size_t i = 0; i < end; ++i) {
            if (sl->_array[i] > sl->_array[i + 1]) {
                size_t tmp = sl->_array[i];
                sl->_array[i] = sl->_array[i + 1];
                sl->_array[i + 1] = tmp;
            }
        }
    }
    printf("����ɹ�!\n");
}

int SeqListBinaryFind(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("˳�������Ԫ��!\n");
        return -1;
    }
    size_t right = sl->_size - 1;
    size_t left = 0;
    size_t mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if (sl->_array[mid] == x) {
            printf("�ɹ��ҵ�Ԫ��%d!\n", x);
            return mid;
        }else if(sl->_array[mid] > x){
            right = mid - 1;
            continue;
        }else if(sl->_array[mid] < x){
            left = mid + 1;
            continue;
        }
    }
    printf("δ�ҵ�%d!\n",x);
    return 1;
}

void SeqListRemoveAll(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("˳�������Ԫ��!\n");
        return;
    }
    size_t i = sl->_size - 1;
    while(i--){
        if(sl->_array[i] != x){
            continue;
        }else{
            SeqListErase(sl,i);
        }
    }
}