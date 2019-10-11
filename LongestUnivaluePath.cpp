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
    int dfs(TreeNode * root, int& len){
        if(root == NULL){
            return 0;
        }
        int left = dfs(root->left, len);
        int right = dfs(root->right, len);
        if(root->left == NULL || root->left->val != root->val){
            left = 0;
        }
        if(root->right == NULL || root->right->val != root->val){
            right = 0;
        }
        len = max(len , left + right);
        return max(left, right) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};