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
    int height(TreeNode * root){
        if(root == 0){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return max(l , r)  + 1;
    }
    void helper(TreeNode * root, int level, int targetLevel, int & res){
        if(root == nullptr){
            return;
        }
        if(level == targetLevel){
            res += root->val;
            return;
        }
        helper(root->left,level + 1, targetLevel, res);
        helper(root->right, level + 1, targetLevel, res);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int res = 0;
        helper(root, 1, h, res);
        return res;
    }
};