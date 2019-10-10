int BSize(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return BSize(root->left) + BSize(root->right) + 1;
}

void _InOrder(struct TreeNode* root , int* a,int* pi ){
    if(root){
        _InOrder(root->left ,a ,pi);
        a[*pi] = root->val;
        ++(*pi);
        _InOrder(root->right ,a ,pi);
        
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* a , i;
    
    *returnSize = BSize(root);
    a = (int*)malloc(sizeof(int) * (*returnSize));
    i = 0;
    _InOrder(root , a , &i);
    return a;
}

