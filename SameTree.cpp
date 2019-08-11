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
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        bool ans = false;
        if(p!=NULL && q!=NULL){
            if(p->val == q->val){
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }else if(p == NULL && q == NULL){
            ans = true;
        }
        return ans;
    }
};
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }else if((p!=NULL && q!=NULL) && p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else{
            return false;
        }
    }
};