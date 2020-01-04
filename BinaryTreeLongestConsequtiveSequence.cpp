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
    void dfs(TreeNode * root, int prev , int curr, int & res){
        res = max(res, curr);
        if(root!= nullptr){
            if(prev + 1 == root->val){
                dfs(root->left, root->val, curr + 1, res);
                dfs(root->right, root->val, curr + 1, res);
            }else{
                dfs(root->left, root->val, 1, res);
                dfs(root->right, root->val, 1, res);
            }
        }
    }
    int longestConsecutive(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(root == nullptr || (!root->left && !root->right)){
            return root==nullptr ? 0 : 1;
        }
        int res = INT_MIN;
        int prev = INT_MIN;
        dfs(root, prev, 1, res);
        return res;
    }
};