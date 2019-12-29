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
    void dfs(TreeNode * root, vector<int>& res){
        if(root != nullptr){
            res.push_back(root->val);
            dfs(root->left, res);
            dfs(root->right, res);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        dfs(root1, res);
        dfs(root2, res);
        sort(res.begin(), res.end());
        return res;
    }
};