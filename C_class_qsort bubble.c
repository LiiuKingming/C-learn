#include <stdio.h>

void Swap(int* x,int * y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

typedef int(*Cmp)(int,int);

int BulleSort(int arr[],int size,Cmp cmp){
    int bound = 0;
    for (; bound <size ; ++bound) {
        for (int cur = size-1; cur > bound ; -- cur) {
            if(cmp(arr[cur-1],arr[cur])){
                Swap(&arr[cur-1],&arr[cur]);
            }
        }
    }
}

int Less(int x,int y){//升序
    if(x < y){
        return 0;
    }
    return 1;
}

int Greater(int x,int y){//降序
    if(x > y){
        return 0;
    }
    return 1;
}

int  main(){
    int arr1[]={9,5,2,7};
    int arr2[]={9,5,2,7};
    int size1= sizeof(arr1)/ sizeof(arr1[0]);
    BulleSort(arr1,size1,Less);
    for (int i = 0; i <size1 ; ++i) {
        printf("%d ",arr1[i]);
    }
    int size2= sizeof(arr2)/ sizeof(arr2[0]);
    printf("\n");
    BulleSort(arr2,size2,Greater);
    for (int i = 0; i <size2 ; ++i) {
        printf("%d ",arr2[i]);
    }
    return 0;
}