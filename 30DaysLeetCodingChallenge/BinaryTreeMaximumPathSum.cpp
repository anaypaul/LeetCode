/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode * root, int & res){
        if(!root){
            return 0;
        }
        int leftSubtree = max(dfs(root->left, res), 0);
        int rightSubtree = max(dfs(root->right, res), 0);
        int val = root->val + leftSubtree + rightSubtree;
        res = max(res, val);
        return root->val + max(leftSubtree , rightSubtree);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};