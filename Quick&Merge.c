//����ȡ�з�
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

    //���һ��С��key��λ��
    int prev = left;
    //��һ��С��key��λ��
    int cur = left + 1;
    int key = a[left];
    while (cur <= right){
        //�����һ��С��key��λ������һ��С��key��λ�ò�����
        //˵���м��д���key��ֵ, ���н���, ��-->����ƶ�, С<--��ǰ�ƶ�
        if(a[cur]< key && ++prev != cur){//������
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
        //���ұ���С
        while (left > right && a[right] >= key){
            --right;
        }
        a[left] = a[right];
        //������Ҵ��
        while (left < right && a[right] <= key)
            ++left;
        //���
        a[right] = a[left];
    }
    //���key
    a[left] = key;
    return left;
}

//���ŵ�һ������:ȷ����׼ֵ��λ��
int PartSort(int* a, int left, int right){
    int mid = getMid(a, left, right);
    Swap(&a[mid], &a[left]);

    int key = a[left];
    int start = left;
    //Ѱ�Ҵ�СԪ�ؽ���
    while(left < right){
        //�ȴ��ұ���С��key��ֵ
        while(left < right && a[right] >= key)
            --right;
        //������Ҵ���key��ֵ
        while(left < right && a[left] <= key)
            ++left;
        Swap(&a[left], &a[right]);
    }
    //key��λ��ȷ�� : left right ������λ��
    Swap(&a[start], &a[left]);
    return left;
}
//�ռ�: �ռ���Ը��� ���ĵݹ������--> logN
//ʱ��: N * logN
//�������� ʱ��Ч�����--> N^2
void QuickSort(int* a, int left, int right){
    if(left >= right)
        return;
    //С�����Ż�: С���䲻�ٵ��õݹ�
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
        //���ֵ�ǰ����
        int mid = PrevCurPointer(a, begin, end);
        //��������������
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

//ʱ��: N * logN
//�ռ�: N + logN ~ N
//�ȶ�
void _MergeSort(int*a, int left, int right, int* tmp){
    //����ֻʣһ��Ԫ��, ����Ҫ�ֽ�͹鲢
    if(left >= right)
        return;
    //�ֽ�
    int mid = left + (right - left) / 2;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    //�鲢 [left, mid] , [mid + 1, right]
    int begin1 = left, end1 = mid,
        begin2 = mid + 1, end2 = right;  //begin1 ~ end2 --> left ~ right
    int tmpindex = begin1;
    while (begin1 <= end1 && begin2 <= end2){
        // < ���ȶ�   <= �ȶ�
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
    //������ԭ������Ķ�Ӧ����
    memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* a, int n){
    int* tmp = (int*)malloc(sizeof(int));
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
    tmp = NULL;
}

//��������
void CountSort(int* a, int n){
    //��Χ: min ~ max
    int min = a[0], max = a[0];
    int i;
    //��ȡ���ݷ�Χ ���п��� ��ʡ�ռ�
    for (i = 1; i < n; ++i){
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int* CountArr = (int*)malloc(sizeof(int) * range);
    memset(CountArr, 0, sizeof(int) * range);
    //����
    for (i = 0; i < n; ++i) {
        CountArr[a[i] - min]++;
    }
    //����
    int index = 0;
    for (i = 0; i < n; ++i) {
        while(CountArr[i]--){
            a[index] = i + min;
        }
    }
}