#include <stdio.h>

//题目要求找出字符串中第一个只出现一次的字符,且时间复杂度为O(n)
//第一种方法时间复杂度为O(n*n),不符合要求
int FindChar1(char arr[],int size) {
    for (int i = 0; i <size ; ++i) {
        int count=0;
        for (int j = 0; j <size ; ++j) {
            while(i==j){
                ++j;
            }
            if(arr[i]==arr[j]){
                ++count;
                break;
            }
        }
        if(count==0){
            printf("%c\n",arr[i]);
            return  0;
        }
    }
}

int FindChar(char* p,int size){
    if(p==NULL){
        return -1;
    }
    int arr1[256]={0};//初始化一个数组
    char* q=p;
    while(*q !='\0'){//出现的字符,其ascii码对应为在arr1中的下标,每出现一次该元素加1,
        arr1[*q]++;
        q++;
    }
    q=p;
    while ( *q !='\0'){
        if(arr1[*q]==1){
            return *q;
        }
        q++;
    }
}
int main(){
    char arr[]="abgbacdcdffe";
    int size= sizeof(arr)/ sizeof(arr[0]);
    printf("%c",FindChar(arr,size));
    return 0;
}



