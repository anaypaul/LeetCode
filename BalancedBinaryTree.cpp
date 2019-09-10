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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(abs(height(root->left) - height(root->right)) >1){
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return true;
    }
};