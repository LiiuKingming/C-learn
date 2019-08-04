#include <stdio.h>
#include <string.h>

void replace(char* arr){
    int len=0;
    len=strlen(arr);
    int blockNum=0;
    int oldlen=len;
    int newlen=0;
    for(int i=0;i<len;i++){
        if(arr[i]==' '){
            blockNum++;
        }
    }
    newlen=oldlen+blockNum*2;
    printf("处理前的字符串为:%s\n",arr);
    while(oldlen<=newlen&&oldlen>=0){
        if(arr[oldlen]!=' '){
            arr[newlen]=arr[oldlen];
            newlen--;
            oldlen--;
        }
        else{
            arr[newlen--]='0';
            arr[newlen--]='2';
            arr[newlen--]='%';
            oldlen--;
        }
    }
    printf("处理后的字符串为:%s\n",arr);
}

int main(){
    char a[]="abc defgx yz";
    replace(a);

    return 0;
}//
// Created by 28943 on 2019/7/28.
//

