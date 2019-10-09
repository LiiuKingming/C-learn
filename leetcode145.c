int BSize(struct TreeNode* root){
    if(root == NULL)
        return 0;
    return BSize(root->left) + BSize(root->right) + 1;
}

void _PostOrder(struct TreeNode* root, int* a, int* pi){
    if(root){
        _PostOrder(root->left, a , pi);
        _PostOrder(root->right, a , pi);
        a[*pi] = root->val;
        ++(*pi);
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* a , i;
    *returnSize = BSize(root);
    a = (int*)malloc(sizeof(int) * (*returnSize));
    i = 0;
    _PostOrder(root , a , &i);
    return a;
}