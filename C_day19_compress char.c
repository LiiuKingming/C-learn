#include <stdio.h>
#include <string.h>
#include <assert.h>

void Compression(char *arr){
    assert(arr !=NULL);
    int len=strlen(arr);
    int count=1;
    for (int i = 0; i < len ; ++i) {
        if(arr[i]==arr[i+1]){
            ++count;
        }else{
            if(count==1){
                printf("%c",arr[i]);
            }else{
                printf("%d%c",count,arr[i]);
                count=1;
            }
        }
    }
    printf("\n");
}

int main(){
    Compression("xxxyyyyz");
    return 0;
}