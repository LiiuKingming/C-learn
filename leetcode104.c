/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    //每一层的高度就是他的两个子树的高度最大值 + 1
    if(root == NULL)
        return 0;
    else{
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        if(left > right)
            return left;
        else
            return right;
    }
    // return root ? 
    // 1 + fmax(maxDepth(root->left) , maxDepth(root->right)) : 0;
}