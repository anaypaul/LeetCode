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
private:
    int res = INT_MIN;
public:
    int dfs(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int left_sum = max(0, dfs(root->left));
        int right_sum = max(0, dfs(root->right));
        int new_sum = root->val + left_sum + right_sum;
        res = max(res, new_sum);
        return root->val + max(left_sum , right_sum);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
        
    }
};