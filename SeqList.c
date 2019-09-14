//
// Created by 28943 on 2019/9/4.
//
#include "SeqList.h"

void SeqListInit(SeqList* sl,size_t capacity){//初始化
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
void SeqListDestory(SeqList* sl){//摧毁释放内存
    assert(sl);
    free(sl->_array);
    sl->_array = NULL;
    sl->_capacity = 0;
    sl->_size = 0;
    printf("成功销毁!\n");
}

void CheckCapacity(SeqList* sl){//检查容量及扩容
    assert(sl);
    if(sl->_size == sl->_capacity){
        sl->_capacity += INCREASE_SIZE;//增加两倍
        sl->_array = (DataType*)realloc(sl->_array,sizeof(DataType) * sl->_capacity);
    }
}

void SeqListPushBack(SeqList* sl,DataType x){//尾插
    assert(sl);
    CheckCapacity(sl);
    /*
    sl->_array[sl->_size] = x;
    ++sl->_size;
    printf("%d添加成功!\n",x);
     */
    SeqListInsert(sl, sl->_size, x);
}

void SeqListPopBack(SeqList* sl){//尾删
    assert(sl);
    CheckCapacity(sl);
    /*
    if(sl->_size == 0){
        printf("删除失败,顺序表中没有元素!\n");
        return;
    }
    --sl->_size;
    printf("删除末位元素成功!\n");
     */
    SeqListErase(sl,sl->_size);
}

void SeqListPushFront(SeqList* sl,DataType x){//头插
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
    printf("%d插入首元素位置成功!\n",x);
 */
    SeqListInsert(sl,0,x);

}

void SeqListPopFront(SeqList* sl){//头删
    assert(sl);
    CheckCapacity(sl);
    /*
    if(sl->_size == 1){
        --sl->_size;
        printf("首元素删除成功!\n");
    }else{
        for (size_t i = 0; i < sl->_size - 1; ++i) {
            sl->_array[i] = sl->_array[i + 1];
        }
        --sl->_size;
        printf("首元素删除成功!\n");
    }
     */
    SeqListErase(sl,0);
}

void SeqListFind(SeqList* sl,DataType x) {//查找指定元素
    assert(sl);
    if (sl->_size == 0) {
        printf("查找失败,顺序表中没有元素!\n");
    }

    int count = 0;
    for (size_t i = 0; i < sl->_size; ++i) {
        if (x == sl->_array[i]) {
            ++count;
            if (count > 1) {
                printf("以及第%d位上\n", i);
                continue;
            }
            printf("%d位于第%d位上\n", x, i);
        }
    }
    if (count == 0) {
        printf("查找失败,顺序表中没有该元素!\n");
    }
}

void SeqListInsert(SeqList* sl,size_t pos,DataType x){//指定位置插入元素
    assert(sl);
    if(pos < 0||pos > sl->_size){
        printf("插入失败,输入了错误的位置!\n");
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
        printf("成功添加新末尾元素!\n");
    } else if (pos == 0) {
        printf("成功增加新首元素!\n");
    } else {
        printf("成功增加第%d个元素!\n", pos);
    }
    /*
    if(pos == 0){//直接调用头插
        SeqListPushFront(sl,x);
    }else if(pos == sl->_size){//直接调用尾插
        SeqListPushBack(sl,x);
    }else{
    } */
}

void SeqListErase(SeqList* sl,size_t pos) {//删除指定位置元素
    assert(sl);
    if (sl->_size == 0) {
        printf("删除失败,顺序表中没有元素!\n");
    }
    if(pos < 0||pos > sl->_size){
        printf("删除失败,输入了错误的位置!\n");
        return;
    }
    for (size_t i = pos; i < sl->_size - 1; ++i) {
        sl->_array[i] = sl->_array[i + 1];
    }
    --sl->_size;
    if (pos == sl->_size) {
        printf("成功删除末尾元素!\n");
    } else if (pos == 0) {
        printf("成功删除首元素!\n");
    } else {
        printf("成功删除第%d个元素!\n", pos);
    }
}

void SeqListRemove(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("删除失败,顺序表中没有元素!\n");
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
        printf("删除失败,未找到指定的元素!\n");
    }
}

void SeqListModify(SeqList* sl,size_t pos,DataType x){
    assert(sl);
    if (sl->_size == 0) {
        printf("修改失败,顺序表中没有元素!\n");
    }
    if(pos < 0||pos > sl->_size){
        printf("修改失败,输入了错误的位置!\n");
        return;
    }
    int tmp = sl->_array[pos];
    sl->_array[pos] = x;
    printf("成功将第%d号元素%d修改为%d\n",pos,tmp,sl->_array[pos]);
}

void SeqListPrint(SeqList* sl){
    assert(sl);
    if(sl->_size == 0){
        printf("顺序表中无元素!\n");
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

void SeqListBubbleSort(SeqList* sl){//升序冒泡排序
    assert(sl);
    if(sl->_size == 0){
        printf("顺序表中无元素!\n");
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
    printf("排序成功!\n");
}

int SeqListBinaryFind(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("顺序表中无元素!\n");
        return -1;
    }
    size_t right = sl->_size - 1;
    size_t left = 0;
    size_t mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if (sl->_array[mid] == x) {
            printf("成功找到元素%d!\n", x);
            return mid;
        }else if(sl->_array[mid] > x){
            right = mid - 1;
            continue;
        }else if(sl->_array[mid] < x){
            left = mid + 1;
            continue;
        }
    }
    printf("未找到%d!\n",x);
    return 1;
}

void SeqListRemoveAll(SeqList* sl,DataType x){
    assert(sl);
    if(sl->_size == 0){
        printf("顺序表中无元素!\n");
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