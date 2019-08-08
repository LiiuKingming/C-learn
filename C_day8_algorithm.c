#include <stdio.h>

void func(int* arr,int size){

    for (int i = 0; i < size; ++i) {
        int tmp = arr[i];
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (tmp == arr[j]) {
                count++;
            }
        }
        if (count > (size / 2)) {
            printf("出现次数超过字符串长度一般的数字为:%d\n", tmp);
            break;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    func(arr,size);
    return 0;
}


