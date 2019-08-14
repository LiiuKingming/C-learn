#include <stdio.h>
#include <string.h>

int main(){
    char arr1[]="aeiou";
    char arr2[]="They are stuidents.";
    int len1=(int) strlen(arr1);
    int len2= (int)strlen(arr2);
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j <len2 ; ++j) {
            while(arr2[j]==arr1[i]){
                for (int k = j; k <len2 ; ++k) {
                    arr2[k]=arr2[k+1];
                }
            }
        }
    }
    printf("%s\n",arr2);

    return 0;
}