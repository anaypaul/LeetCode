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
    bool validate(TreeNode *root,long long int min,long long int max){
        if(root==NULL){
            return true;
        }else{
            if(min < root->val && root->val < max){
                return validate(root->left, min , root->val ) && validate(root->right, root->val, max);
            }else{
                return false;
            }
        }
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,INT64_MIN,INT64_MAX);
    }
};