int BSize(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return BSize(root->left)
        + BSize(root->right) + 1;
}

void _preOrder(struct TreeNode* root,int* a,int* pi){
    if(root){
        a[*pi] = root->val;
        ++(*pi);
        _preOrder(root->left , a , pi);
        _preOrder(root->right , a , pi);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    //前序遍历 返回数组大小
    int* a , i;
    *returnSize = BSize(root);
    a = (int*)malloc(sizeof(int) * (*returnSize));
    i = 0;
    _preOrder(root, a, &i);
    return a;
    
}

