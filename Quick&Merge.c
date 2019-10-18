//三数取中法
int getMid(int* a, int left, int right){
    int mid = left + (right - left) / 2;
    if(a[mid] > a[left]){
        if(a[mid] < a[right]){
            return mid;
        }else{
            //mid >left, right
            if(a[left] > a[right]){
                return left;
            }else{
                return right;
            }
        }
    }else{
        //mid <= left
        if(a[left] < a[right]){
            return left;
        }else{
            //left >= right, mid
            if(a[mid] > a[right])
                return mid;
            else
                return right;
        }
    }
}

int PrevCurPointer(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    //最后一个小于key的位置
    int prev = left;
    //下一个小于key的位置
    int cur = left + 1;
    int key = a[left];
    while (cur <= right){
        //如果下一个小于key的位置与上一个小于key的位置不连续
        //说明中间有大于key的值, 进行交换, 大-->向后移动, 小<--向前移动
        if(a[cur]< key && ++prev != cur){//不连续
            Swap(&a[prev], &a[cur]);
        }
        ++cur;
    }
    Swap(&a[prev], &a[left]);
    return prev;
}

int Dig(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);
    int key = a[left];
    while (left < right){
        //从右边找小
        while (left > right && a[right] >= key){
            --right;
        }
        a[left] = a[right];
        //从左边找大的
        while (left < right && a[right] <= key)
            ++left;
        //填坑
        a[right] = a[left];
    }
    //存放key
    a[left] = key;
    return left;
}

//快排的一次排序:确定基准值的位置
int PartSort(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    int key = a[left];
    int start = left;
    //寻找大小元素交换
    while(left < right){
        //先从右边找小于key的值
        while(left < right && a[right] >= key)
            --right;
        //从左边找大于key的值
        while(left < right && a[left] <= key)
            ++left;
        Swap(&a[left], &a[right]);
    }
    //key的位置确定 : left right 相遇的位置
    Swap(&a[start], &a[left]);
    return left;
}
//空间: 空间可以复用 最大的递归调用链--> logN
//时间: N * logN
//序列有序 时间效率最差--> N^2
void QuickSort(int* a, int left, int right){
    if(left >= right)
        return;
    //小区间优化: 小区间不再调用递归
    else if(right - left + 1 < 5){
        InsertSort(a + left, right - left + 1);
    }else{
    int mid = PartSort(a, left, right);
    QuickSort(a, left, mid - 1);
    QuickSort(a, mid + 1, right);

    }
}

void QuickSortNoR(int* a, int left, int right){//typedef int STDatatype
    Stack st;
    StackInit(&st);
    if(left < right){
        StackPush(&st, right);
        StackPush(&st, left);
    }
    while (StackEmpty(&st) == 0){
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);
        //划分当前区间
        int mid = PrevCurPointer(a, begin, end);
        //划分左右子区间
        if(begin < mid - 1){
            StackPush(&st, mid - 1);
            StackPush(&st, begin);
        }
        if(mid + 1 < end){
            StackPush(&st, end);
            StackPush(&st, mid + 1);
        }
    }
}

//时间: N * logN
//空间: N + logN ~ N
//稳定
void _MergeSort(int*a, int left, int right, int* tmp){
    //区间只剩一个元素, 不需要分解和归并
    if(left >= right)
        return;
    //分解
    int mid = left + (right - left) / 2;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    //归并 [left, mid] , [mid + 1, right]
    int begin1 = left, end1 = mid,
        begin2 = mid + 1, end2 = right;  //begin1 ~ end2 --> left ~ right
    int tmpindex = begin1;
    while (begin1 <= end1 && begin2 <= end2){
        // < 不稳定   <= 稳定
        if (a[begin1] <= a[begin2]){
            tmp[tmpindex++] = a[begin1++];
        }else{
            tmp[tmpindex++] = a[begin2++];
        }
    }
    while (begin1 <= end1){
        tmp[tmpindex++] = a[begin1++];
    }
    while (begin2 <= end2){
        tmp[tmpindex++] = a[begin2++];
    }
    //拷贝到原有数组的对应区间
    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* a, int n){
    int* tmp = (int*)malloc(sizeof(int));
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
    tmp = NULL;
}

//计数排序
void CountSort(int* a, int n){
    //范围: min ~ max
    int min = a[0], max = a[0];
    int i;
    //获取数据范围 可有可无 节省空间
    for (i = 1; i < n; ++i){
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int* CountArr = (int*)malloc(sizeof(int) * range);
    memset(CountArr, 0, sizeof(int) * range);
    //计数
    for (i = 0; i < n; ++i) {
        CountArr[a[i] - min]++;
    }
    //排序
    int index = 0;
    for (i = 0; i < n; ++i) {
        while(CountArr[i]--){
            a[index] = i + min;
        }
    }
}