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
    bool isUnivalTree(TreeNode* root) {
        return ( root->left==NULL || root->left->val == root->val && isUnivalTree(root->left)) && 
            ( root->right==NULL || root->right->val== root->val && isUnivalTree(root->right));
    }
};