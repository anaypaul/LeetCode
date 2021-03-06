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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * x = root;
        if(root==NULL){
            TreeNode * temp = new TreeNode(val);
            root = temp;
            x = root;
        }
        if(val > root->val){
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }else{
                root->right = insertIntoBST(root->right, val);
            }
        }
        else if(val < root->val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }else{
                root->left = insertIntoBST(root->left, val);
            }
        }
        return x;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * curr = root;
        while(curr!=NULL){
            if(val > curr->val){
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                    return root;
                }else{
                    curr = curr->right;
                }
            }else{
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                    return root;
                }else{
                    curr = curr->left;
                }
            }
        }
        return new TreeNode(val);
    }
};