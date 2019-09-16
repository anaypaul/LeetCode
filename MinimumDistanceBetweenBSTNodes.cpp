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
    int prev = INT_MIN , ans=INT_MAX;
    void dfs(TreeNode * root){
        if(root == NULL ){
            return ;
        }
        dfs(root->left);
        if(prev != INT_MIN){
            ans = min(ans , root->val - prev);
        }
        prev = root->val;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> arr;
        dfs(root);
        return ans;
        
    }
};