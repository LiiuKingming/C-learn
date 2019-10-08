/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q !=NULL)
        return false;
    if(p != NULL && q == NULL)
        return false;
    if(p == NULL && q == NULL)
        return true;
    if(p->val == q->val)
        return isSameTree(p->left , q->left)  && isSameTree(p->right , q->right);
    else
        return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    //一颗空就false
    if(s == NULL)
        return false;
    //根相同 判断当前这个树是否和t相同
    if(s->val == t->val && isSameTree(s , t))
        return true;
    return isSubtree(s->left , t) || isSubtree(s->right , t);
}