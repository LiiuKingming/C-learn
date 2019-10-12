typedef struct {
    int* _a;
    int _front;
    int _rear;
    int _k;
} MyCircularQueue;

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->_front == obj->_rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mq->_a = (int*)malloc(sizeof(int) * (k + 1));
    mq->_front = mq->_rear = 0;
    mq->_k = k;
    return mq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //队列是否已满
    if(myCircularQueueIsFull(obj))
        return false;
    //队尾插入
    obj->_a[obj->_rear] = value;
    //更新队尾指针
    obj->_rear++;
    if(obj->_rear == obj->_k + 1)
        obj->_rear = 0;
    
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
      return false;
    //删除头元素
    ++obj->_front;
    if(obj->_front == obj->_k + 1)
        obj->_front = 0;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
      return -1;
    else
        return obj->_a[obj->_front]; 
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
      return -1;
    //rear - 1 :最后一个元素,队尾元素
    if(obj->_rear == 0)
        return obj->_a[obj->_k];
    else
        return obj->_a[obj->_rear - 1];
    
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/