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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }else if(root){
            TreeNode * temp = invertTree(root->right);
            TreeNode *t1 = invertTree(root->left);
            root->left = temp;
            root->right = t1;
        }
        return root;
    }
};