/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// int TreeSize(struct TreeNode* root){//节点个数
//     if(root == NULL)
//         return 0;
//     return TreeSize(root->left) + TreeSize(root->right) + 1;
// }

// void _preOrder(struct TreeNode* root , int* arr , int* pi){
//     if(root){
//         arr[*pi] = root->val;
//         ++(*pi);
//         _preOrder(root->left , arr , pi);
//         _preOrder(root->right , arr ,pi);
//     }
// }

// int* preOrder(struct TreeNode* root , int* returnSize){
//     int  i = 0;
//     *returnSize = TreeSize(root);
//     int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//     _preOrder(root , arr , &i);
//     return arr;
// }

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q !=NULL)
        return false;
    if(p != NULL && q == NULL)
        return false;
    if(p == NULL && q == NULL)
        return true;
    if(p->val == q->val)
        return isSameTree(p->left , q->left)  
            && isSameTree(p->right , q->right);
    else
        return false;
}