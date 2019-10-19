/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//��һ������ O(n)
bool _isBalanced(struct TreeNode* root , int* curDepth){
    if(root == NULL){
        //�����߶�Ϊ0
        *curDepth = 0;
        return true;
    }
    //curDepth �Ե�ǰ�ڵ�Ϊ���ĸ߶�
    int leftDepth = 0 , rightDepth = 0;
    if(_isBalanced(root->left , &leftDepth) 
    && _isBalanced(root->right , &rightDepth)
    && abs(leftDepth - rightDepth) < 2){
        //��ǰ���ĸ߶� max(leftDepth , maxDepth)
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