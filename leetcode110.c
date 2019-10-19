/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//另一个方法 O(n)
bool _isBalanced(struct TreeNode* root , int* curDepth){
    if(root == NULL){
        //空树高度为0
        *curDepth = 0;
        return true;
    }
    //curDepth 以当前节点为根的高度
    int leftDepth = 0 , rightDepth = 0;
    if(_isBalanced(root->left , &leftDepth) 
    && _isBalanced(root->right , &rightDepth)
    && abs(leftDepth - rightDepth) < 2){
        //当前数的高度 max(leftDepth , maxDepth)
        *curDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
        return true;
    }else{
        return false;
    }
}

int maxDepth(struct TreeNode* root){
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
}

bool isBalanced(struct TreeNode* root){
    int depth = 0;
    return _isBalanced(root , &depth);
    // if(root == NULL)
    //     return true;
    // int left = maxDepth(root->left);
    // int right = maxDepth(root->right);
    // return abs(left - right) < 2
    //     && isBalanced(root->left)
    //     && isBalanced(root->right);
}