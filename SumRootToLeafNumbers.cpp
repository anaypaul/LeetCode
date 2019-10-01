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
    bool isLeaf(TreeNode * root){
        return root->left == NULL && root->right == NULL;
    }
    void dfs(TreeNode * root,long long int value,long long int & ans){
        if(root){
            if(isLeaf(root)){
                value = 10 * value + root->val;
                ans += value;
            }
            value = value * 10 + root->val;
            if(root->left){
                dfs(root->left, value, ans);
            }
            if(root->right){
                dfs(root->right, value , ans);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        long long int ans = 0;
        dfs(root,0, ans);
        return ans;
    }
};