#include <stdio.h>

int main(){
    int arr[]={1,3,5,7,1,3,5,9};
    int size= sizeof(arr)/ sizeof(arr[0]);
    for (int i = 0; i <size ; ++i) {
        int count=0;
        for (int j = 0; j <size ; ++j) {
            while(i==j){
                ++j;
            }
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==0){
            printf("%d\n",arr[i]);
        }
    }

    return 0;
}
