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
    TreeNode* searchBST2(TreeNode* root, int val) {
        if(root == NULL || root->val == val){
            return root;
        }
        if(root->val > val){
            return searchBST(root->left, val);
        }else{
            return searchBST(root->right, val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return root;
        }
        TreeNode * ans = NULL;
        if(root->val == val){
            ans =  root;
        }else if(val < root->val){
            ans =  searchBST(root->left, val);
        }else if(val > root->val){
            ans = searchBST(root->right, val);
        }
        return ans;
    }
};