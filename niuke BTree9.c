#include<stdio.h>
#include<malloc.h>

typedef struct BTNode{
    char _data;
    struct BTNode* left;
    struct BTNode* right;
}BTNode;

void InOrder(BTNode* root){
    if(root){
        InOrder(root->left);
        printf("%c ", root->_data);
        InOrder(root->right);
    }
}

BTNode* CreatTree(char* str , int* pi){
    if(str[*pi] != '#'){
        BTNode* root = (BTNode*)malloc(sizeof(BTNode));
        root->_data = str[*pi];
        ++(*pi);
        root->left = CreatTree(str , pi);
        ++(*pi);
        root->right = CreatTree(str , pi);
        return root;
    }else{
        return NULL;
    }
    
}

int main(){
    char str[101];
    int i = 0;
    //读入字符串
    scanf("%s" , str);
    //创建二叉树
    BTNode* root = CreatTree(str , &i);
    //中序打印二叉树
    InOrder(root);
    printf("\n");
    return 0;
    
}