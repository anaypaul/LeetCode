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
    bool validate(TreeNode *root, int low, int high){
        if(root==NULL){
            return true;
        }else{
            if(low <= int(root->val) && int(root->val) <= right){
                return validate(root->left, low , root->data - 1) && validate(root->right, root->data + 1 , right);
            }else{
                return false;
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }
};