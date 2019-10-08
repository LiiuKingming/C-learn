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
    //һ�ſվ�false
    if(s == NULL)
        return false;
    //����ͬ �жϵ�ǰ������Ƿ��t��ͬ
    if(s->val == t->val && isSameTree(s , t))
        return true;
    return isSubtree(s->left , t) || isSubtree(s->right , t);
}