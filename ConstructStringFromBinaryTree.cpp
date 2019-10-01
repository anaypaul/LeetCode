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
    string dfs(TreeNode * root){
        if(root==NULL){
            return "";
        }
        if(root->left == NULL && root->right == NULL){
            return to_string(root->val)+"";
        }
        if(root->right == NULL){
            return to_string(root->val) + "(" + dfs(root->left) + ")";
        }
        return to_string(root->val) + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    }
    string tree2str(TreeNode* t) {
        return dfs(t);
    }
};