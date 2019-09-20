/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL){
            return false;
        }
        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool isSame(TreeNode * p, TreeNode * q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val == q->val){
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        }else{
            return false;
        }
    }
};